#!/usr/bin/env python

'''
trajectory subscriber node to compute the radius of curvature R
'''

import numpy as np
import rospy
import controlpy
from std_msgs.msg import String, Float32

from barc.msg import barc_state, ECU, Input, Moving

def compute_R(data):
	# compute the radius of curvature of the curve ahead given trajectory waypoints
	
	# data x and y are 7 element lists with the first element being the closest point to the vehicle
	traj_x = data.x
	traj_y = data.y

	# we'll use three points as in the lab10 instructions to determine our R
	x1 = traj_x[0] # center of mass point
	y1 = traj_x[0]

	x2 = traj_x[3] # intermediate point
	y2 = traj_y[3]

	x3 = traj_x[6] # farthest ahead point
	y3 = traj_y[6]

	# compute slopes
	ma = (y2 - y1) / (x2 - x1)
	mb = (y3 - y2) / (x3 - x2)

	# compute the center point of the turn
	xc = (ma*mb*(y1-y3) + mb*(x1+x2) - ma*(x2+x3)) / (2*(mb - ma))
	yc = (-1 / ma)*(xc - ((x1+x2)/2) + ((y1+y2)/2))

	# compute the radius of curvature
	R = np.sqrt((x2 - xc)**2 + (y2 - yc)**2)

	return R

def trajectory_callback(data):
	# compute the radius of curvature given the trajectory waypoints
	rad = compute_R(data)
	rospy.loginfo("the radius of curvature: " + str(rad))

def listener():
	# init node
	rospy.init_node('compute_R', anonymous=True)

	rospy.Subscriber("reference_trajectory", barc_state, trajectory_callback)

	# spin() simply keeps python from exiting until this node is stopped
	rospy.spin()

if __name__ == '__main__':
	listener()