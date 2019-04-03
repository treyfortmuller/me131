#!/usr/bin/env python

# ---------------------------------------------------------------------------
# Licensing Information: You are free to use or extend these projects for
# education or reserach purposes provided that (1) you retain this notice
# and (2) you provide clear attribution to UC Berkeley, including a link
# to http://barc-project.com
#
# Attibution Information: The barc project ROS code-base was developed at UC
# Berkeley in the Model Predictive Control (MPC) lab by Jon Gonzales
# (jon.gonzales@berkeley.edu) and Greg Marcil (grmarcil@berkeley.edu). The cloud
# services integation with ROS was developed by Kiet Lam
# (kiet.lam@berkeley.edu). The web-server app Dator was based on an open source
# project by Bruce Wootton
# ---------------------------------------------------------------------------

# README: This node serves as an outgoing messaging bus from odroid to arduino
# Subscribes: steering and motor commands on 'ecu'
# Publishes: combined ecu commands as 'ecu_pwm'

from rospy import init_node, Subscriber, Publisher, get_param
from rospy import Rate, is_shutdown, ROSInterruptException, spin, on_shutdown
from barc.msg import ECU
from numpy import pi
import rospy
import time

motor_pwm = 1500
servo_pwm = 1520

# from encoder
v_meas      = 0.0
t0          = time.time()
r_tire      = 0.05 # radius of the tire
ang_km1 = 0
ang_km2 = 0
vel_series = [0] * 10 # initialize a velocity estimate series of 10 zeros

# encoder measurement update
def enc_callback(data):
    global t0, v_meas
    global n_FL, n_FR, n_BL, n_BR
    global ang_km1, ang_km2
    global vel_series

    n_FL = data.FL
    n_FR = data.FR
    n_BL = data.BL
    n_BR = data.BR

    # figure out which encoders are working best
    # rospy.logwarn("~~~~~ ENCODER OUTPUTS ~~~~~")
    # rospy.logwarn("FL = {}".format(n_FL))
    # rospy.logwarn("FR = {}".format(n_FR))
    # rospy.logwarn("BL = {}".format(n_BL))
    # rospy.logwarn("BR = {}".format(n_BR))

    # compute the average encoder measurement, FR and BR are best
    n_mean = (n_BR + n_FR)/2

    # transfer the encoder measurement to angular displacement
    ang_mean = n_mean*2*pi/8

    # compute time elapsed
    tf = time.time()
    dt = tf - t0

    # compute a raw velocity estimate using 2nd order backwards finite method
    v_est = r_tire*(3*ang_mean - 4*ang_km1 + ang_km2)/(2*dt)
    
    # shift all the elements of vel_series popping the last one
    # and replacing the first element with the new measurement
    vel_series.pop() # pops the last item in the list
    vel_series.insert(0, v_est) # insert the latest estimate at the front of the list

    # reported measurement for control is an average of 10 measurements
    v_meas = sum(vel_series)/len(vel_series)

    # rospy.logwarn("velocity = {}".format(v_meas))
    # update old data
    ang_km2 = ang_km1
    ang_km1 = ang_mean
    t0      = time.time()

def arduino_interface():
    global ecu_pub, motor_pwm, servo_pwm

    # initialize node
    init_node('arduino_interface')
    
    # setup publishers and subscribers
    loop_rate   = 50
    dt          = 1.0 / loop_rate
    rate        = rospy.Rate(loop_rate)
    time_prev = time.time()

    ecu_pub = Publisher('ecu_pwm', ECU, queue_size = 10)
    v_meas_pub = rospy.Publisher('v_meas', Float32, queue_size = 10)

    rospy.Subscriber('encoder', Encoder, enc_callback)

    while not rospy.is_shutdown():
        if time.time() >= time_prev and time.time() < time_prev + 4: 
            motor_pwm = 1650
        if time.time() >= time_prev + 4:
            motor_pwm = 1500
     
        ecu_cmd = ECU(motor_pwm, servo_pwm)
        ecu_pub.publish(ecu_cmd)
        v_meas_pub.publish( Float32(v_meas) )

        # wait
        rate.sleep()

if __name__ == '__main__':
    try:
        arduino_interface()
    except ROSInterruptException:
        pass
