#!usr/bin/env python

'''
A listener that retrieves the image stream from the cam_stream topic.
'''

import cv2
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

bridge = CvBridge()

def retrieveImage(imgmsg):
    try:
        mat = bridge.imgmsg_to_cv2(imgmsg, "rgb8")
        cv2.imshow("Image stream", mat)
        cv2.waitKey(1)
    except CvBridgeError as e:
        print(e)
        rospy.loginfo(e)

def listener():
    # subscribe to the image stream topic and call retrieveImage function as a callback
    rospy.init_node('cam_stream_listener', anonymous=True)
    rospy.Subscriber('cam_stream', Image, retrieveImage)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
