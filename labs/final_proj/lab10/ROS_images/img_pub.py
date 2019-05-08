#!usr/bin/env python

'''
A script to run an OpenCV image capture and publish the images to the cam_stream topic
'''

import cv2
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

# ros node and publisher setup
rospy.init_node('camera', anonymous=True)
cam_stream_pub = rospy.Publisher('cam_stream', Image, queue_size=10)

loop_rate = 30 # 30 frames per second
rate = rospy.Rate(loop_rate)

# init video capture
cap = cv2.VideoCapture(0)

# init CV/ROS image bridge
bridge = CvBridge()

def img_getter():

	while not rospy.is_shutdown():

		# get a new frame
		ret, frame = cap.read()

		# publish the streamed images
		try:
		    cam_stream_pub.publish(bridge.cv2_to_imgmsg(frame, "rgb8"))
		except CvBridgeError as e:
		    print(e)

		rate.sleep()

	# release the capture
	cap.release()
	cv2.destroyAllWindows()

if __name__ == '__main__':
    try:
       img_getter()
    except rospy.ROSInterruptException:
        pass
