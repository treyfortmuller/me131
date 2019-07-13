#!/usr/bin/env python
'''
A script for computing the LQR optimal gain matrix K for the reference tracking LQR
lane keeping controller on the BARC
'''

from __future__ import print_function, division

import controlpy # mark's python control library
import numpy as np
import rospy
from std_msgs.msg import Float32,Float64
from numpy import sin,cos,arcsin,arctan,tan
from barc.msg import ECU, Input

lr = 0.1651
lf = 0.1651

v_ref = 1.0 # reference speed
# dt = 0.0333 # 30 frames per second?

def camera_callback(data):
	global R
	R = data.data
	if R<0 and R> -0.2:
		R = -0.2
	if R>0 and R<0.2:
		R = 0.2

def steering_callback(data):
	global d_f
	data = data.servo

	d_f = data * (-0.001127)
	d_f = (d_f+1.732)
	# print(d_f)

def speed_callback(data):
	global v
	v = data.data

def dt_callback(data):
	global dt
	dt = data.data

def barc_uOpt():

	rospy.init_node('optimal_input',anonymous = True)

	rospy.Subscriber('track_radius', Float32 ,camera_callback ) # get R 

	rospy.Subscriber('velocity_estimate', Float32, speed_callback ) # get v, d_f
	rospy.Subscriber('ECU',ECU ,steering_callback )
	rospy.Subscriber('dt',Float64,dt_callback)

	uOpt_pub = rospy.Publisher('uOpt', Input, queue_size = 1)

	global d_f
	global R
	global v
	global dt

	R = 1
	d_f = 0.01
	v = 0
	dt = 0.05

	loop_rate = 30
	rate = rospy.Rate(loop_rate)

	while not rospy.is_shutdown():

		# calculate state 
		beta_ref = arcsin(lr/R);
		# print(beta_ref)
		phi_ref = v_ref/R*dt;
		# print(phi_ref)
		beta = arctan(tan(d_f)*lr/(lr+lf))
		# print(beta)

		vx = v*sin(beta)
		vy = v*sin(beta)
		phidot = v/lr*sin(beta)

		# system dynamics matrices in continuous time
		u1 = v_ref
		u2 = beta_ref

		Ac = np.matrix([[0,0,-u1*sin(u2+phi_ref)],[0,0,u1*cos(u2+phi_ref)],[0,0,0]])
		# print(Ac)
		Bc = np.matrix([[cos(u2+phi_ref),-u1*sin(u2+phi_ref)],[sin(u2+phi_ref),u1*sin(u2+phi_ref)],[sin(u2)/lr,u1*cos(u2)/lr]])
		# print(Bc)
		# define our cost matrices
		Q = 0.000001*np.matrix([[1,0,0],[0,1,0],[0,0,1]])#0.001
		RR = np.matrix([[1,0],[0,1]])

		# define the sampling time of the discrete controller
		# compute the LQR controller
		K, X, clEigVals = controlpy.synthesis.controller_lqr_discrete_from_continuous_time(Ac,Bc,Q,RR, dt)

		# compute actual input
		phi_now = 0
		z = np.matrix([[vx],[vy],[phi_now]])
		z_ref = np.matrix([[v_ref*sin(beta+phi_ref)],[v_ref*cos(beta+phi_ref)],[phi_ref]])


		u_LQR = -K*(z-z_ref) + np.matrix([[u1],[u2]])
		# print(dt)
		# print(-K*(z-z_ref))
		print(phi_ref)

		u = Input()
		u.vel = u_LQR[0]
		u.delta = u_LQR[1]*1.0

		uOpt_pub.publish(u) # publish the optimal output obtained by LQR

		# print('The computed gain matrix is:')
		# print(u_LQR)

		# print('The closed loop eigenvalues are:')
		# print(clEigVals)
		# print("+++++++++++++")
		rate.sleep()

if __name__ == '__main__':
	try:
		barc_uOpt()
	except rospy.ROSInterruptException:
		pass
