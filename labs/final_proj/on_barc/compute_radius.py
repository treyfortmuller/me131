#!/usr/bin/env python

'''
a node to subscribe to the reference trajcetory, 
compute the radius of curvature R of the track, and then publish
the radius of curvature to a topic R.
'''

import numpy as np
import rospy
import controlpy
from std_msgs.msg import String, Float32
from barc.msg import barc_state, ECU, Input, Moving

# node setup
rospy.init_node('compute_R', anonymous=True)

def radius_publisher(radius):
	pub = rospy.Publisher('track_radius', Float32, queue_size=32)
	pub.publish(radius)

def compute_R(data):
	# compute the radius of curvature of the curve ahead given trajectory waypoints, returns -1
	# if the road is so straight we get a divide by 0 in our curvature calculations

	# data x and y are 7 element lists with the first element being the closest point to the vehicle
	traj_x = data.x
	traj_y = data.y

	# we'll use three points as in the lab10 instructions to determine our R
	x1 = traj_x[0] # center of mass point
	y1 = traj_y[0]

	x2 = traj_x[3] # intermediate point
	y2 = traj_y[3]

	x3 = traj_x[6] # farthest ahead point
	y3 = traj_y[6]

	# compute slopes
	try:
		ma = (y2 - y1) / (x2 - x1)
		mb = (y3 - y2) / (x3 - x2)
	except ZeroDivisionError:
		return -1

	#ma = (y2 - y1) / (x2 - x1)
	#mb = (y3 - y2) / (x3 - x2)

	# compute the center point of the turn
	xc = (ma*mb*(y1-y3) + mb*(x1+x2) - ma*(x2+x3)) / (2*(mb - ma))
	yc = (-1 / ma)*(xc - ((x1+x2)/2) + ((y1+y2)/2))

	# compute the radius of curvature
	R = np.sqrt((x2 - xc)**2 + (y2 - yc)**2)

	if yc >= 0:
		return R
	else:
		return -R

def trajectory_callback(data):
	# compute the radius of curvature given the trajectory waypoints then
	# publish it to track_radius topic at every callback
	rad = compute_R(data)

	# if the compute_R function hits a divide by 0 error, return a very large radius
	if rad == -1:
	    rad = 1000

	# rospy.loginfo("the radius of curvature: " + str(rad))
	radius_publisher(rad)

def listener():
	rospy.Subscriber("reference_trajectory", barc_state, trajectory_callback)

	# spin() simply keeps python from exiting until this node is stopped
	rospy.spin()

if __name__ == '__main__':
	listener()
