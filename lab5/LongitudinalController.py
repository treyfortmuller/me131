import rospy
import time
from barc.msg import ECU, Encoder
from numpy import pi

v_meas = 0.0
t0 = time.time()
r_tire = 0.05
servo_pwm = 1540
motor_pwm = 1500

v_ref = 0.5

def enc_callback(data):
    global t0, v_meas
    global n_FL, n_FR, n_BL, n_BR
    global ang_km1, ang_km2
    
    n_FL = data.FL
    n_FR = data.FR
    n_BL = data.BL
    n_BR = data.BR
    
    # compute from encoder measurement
    n_mean = (n_FL + n_FR)/2
    
    ang_mean = n_mean*2*pi/8
    
    tf = time.time()
    dt = tf - t0
    
    v_meas = r_tire * (ang_mean - ang_km1)/dt
    rospy.logwarn("velocity = {}".fformat(v_meas))
    
    ang_km1 = ang_mean
    ang_km2 = ang_km1
    t0 = time.time()


class PID():
    def _init_(self, kp=1, ki=1, kd=1, integrator=0, derivator=0):
        self.kp = kp
        self.ki = ki
        self.integrator = integrator
        self.integrator_max = 100
        
    def acc_calculate(self, speed_reference, speed_current):
        self.error = speed_reference - speed_current
        
        self.P_effect = self.kp*self.error
        
        self.integrator = self.integrator + self.error
        
        if self.integrator >= self.integrator_max:
            self.integrator = self.integrator_max
            
        self.I_effect = self.ki*self.integrator
        
        
        acc = self.P_effect + self.I_effect
        acc = acc * int(acc < 1800 and acc > 1200) + 1200 * ...
        int(acc <= 1200) + 1800 * int(acc >= 1800)
        
        return acc

def controller():
    global motor_pwm, servo_pwm, motor_pwm_offset
    global v_ref, v_meas
    
    # initialize node
    rospy.init_node('simulationGain', anonymous=True)
    rospy.Subscriber('encoder', Encoder, enc_callback)
    
    ecu_pub = rospy.Publisher('ecu_pwm', ECU, queue_size = 10)
    
    loop_rate = 50
    rate = rospy.Rate(loop_rate)
    
    PID_control = PID(kp=20, ki=5, kd=0)
    
    while not rospy.is_shutdown():
        motor_pwm = PID_control.acc_calculate(v_ref, v_meas)
        
        ecu_pub.publish(ECU(motor_pwm,servo_pwm))
        
        rate.sleep()
        
if __name__ == '__main__':
    try:
        controller()
    except rospy.ROSInterruptException:
        pass
    
