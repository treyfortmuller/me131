#!/usr/bin/env python

import rospy
import time
from barc.msg import ECU, Encoder
from geometry_msgs.msg import Twist # for keyboard teleop
from numpy import pi

# from encoder
v_meas      = 0.0
t0          = time.time()
r_tire      = 0.05 # radius of the tire
servo_pwm   = 1530.0
motor_pwm   = 1500.0
ang_km1 = 0
ang_km2 = 0
vel_series = [0] * 10 # initialize a velocity estimate series of 10 zeros
armed = 0 # arming switch for the controller, 0 == disarmed

motor_pwm_offset = 1500.0

# reference speed 
v_ref = 0.5 # reference speed is 0.5 m/s

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
    
    # compute a raw velocity estimate using 1st order backwards finite method
    # v_meas = r_tire*(ang_mean - ang_km1)/(dt)

    # compute a raw velocity estimate using 2nd order backwards finite method
    v_est = r_tire*(3*ang_mean - 4*ang_km1 + ang_km2)/(2*dt)
    
    # shift all the elements of vel_series popping the last one
    # and replacing the first element with the new measurement
    vel_series.pop() # pops the last item in the list
    vel_series.insert(0, v_est) # insert the latest estimate at the front of the list

	# reported measurement for control is an average of 10 measurements
    v_meas = sum(vel_series)/len(vel_series)

    rospy.logwarn("velocity = {}".format(v_meas))
    # update old data
    ang_km2 = ang_km1
    ang_km1 = ang_mean
    t0      = time.time()

def key_callback(twist):
	global armed
	armed = twist.linear.x
	rospy.logwarn("ARMED? = {}".format(armed))

# reference speed 
v_ref = 0.5 # give reference speed is 0.5 m/s

# ===================================PID longitudinal controller================================#
class PID():
    def __init__(self, kp=1, ki=1, kd=1, integrator=0, derivator=0):
        self.kp = kp
        self.ki = ki
        self.integrator = integrator
        self.integrator_max = 100

    def acc_calculate(self, speed_reference, speed_current):
        self.error = speed_reference - speed_current
        
        # Propotional control
        self.P_effect = self.kp*self.error
        
        # Integral control
        self.integrator = self.integrator + self.error
        
		# Anti windup
        if self.integrator >= self.integrator_max:
           self.integrator = self.integrator_max

        self.I_effect = self.ki*self.integrator

        acc = self.P_effect + self.I_effect

        return acc

# =====================================end of the controller====================================#

# state estimation node
def controller():
    global motor_pwm, servo_pwm, motor_pwm_offset
    global v_ref, v_meas
    
    # Initialize node:
    rospy.init_node('simulationGain', anonymous=True)

    # topic subscriptions / publications
    rospy.Subscriber('encoder', Encoder, enc_callback)
    # the keyboard teleop node subcription
    rospy.Subscriber('key_vel', Twist, key_callback)

    ecu_pub = rospy.Publisher('ecu_pwm', ECU, queue_size = 10)

    v_meas_pub = rospy.Publisher('v_meas', Float32, queue_size = 10)

    v_ref_pub = rospy.Publisher('v_ref', Float32, queue_size = 10)


    # Set node rate
    loop_rate   = 50
    rate        = rospy.Rate(loop_rate)

    # Initialize the PID controller
    PID_control = PID(kp=50, ki=1, kd=0.0)
    # PID_control = PID(kp=20, ki=5, kd=0.0)

    while (not rospy.is_shutdown() and armed == 1):
        # calculate acceleration from PID controller.
        motor_pwm = PID_control.acc_calculate(v_ref, v_meas) + motor_pwm_offset

        # hardstops on outputted PWM
        if motor_pwm > 1700:
            motor_pwm = 1700
        if motor_pwm < 1200:
            motor_pwm = 1200

        # rospy.logwarn("PWM = {}".format(motor_pwm))

        # publish control command
        ecu_pub.publish( ECU(motor_pwm, servo_pwm) )

        # publish the velocity estimate for recording
        v_meas_pub.publish( Float32(v_meas))

        v_ref_pub.publish( Float32(v_ref)) 

        # wait
        rate.sleep()

if __name__ == '__main__':
    try:
       controller()
    except rospy.ROSInterruptException:
        pass
