# ME131 Lab5 Deliverables

Trey Fortmuller - 26037758, code for this lab is available at [github.com/treyfortmuller/me131](github.com/treyfortmuller/me131)

#### 1.1

The closed loop transfer function (reference > velocity):

$$
\frac{V}{R}=\frac{G_pG_c}{1+G_pG_c}\\
\frac{V}{R}=\frac{bk_{p}s + bk_{i}}{s^2+(bk_p-a)s + bk_i}
$$

#### 1.2

Gains to place the closed loop eigenvalues to achieve the natural frequency and damping ratio objective:
$$
k_p = 53,057\\
k_i = 32,400
$$

#### 1.3

The Simulink model for the closed loop longitudinal cruise control system:

![](/home/trey/Semester 8/ME131/lab5/deliverables/cruise_control_mdl.png)

#### 1.4

a) Controller's calculated PWM over time from simulation:

![](/home/trey/Semester 8/ME131/lab5/deliverables/PWM_v_time.jpg)

b) Disturbance Step inputs plotted against time:

![](/home/trey/Semester 8/ME131/lab5/deliverables/disturbances.jpg)

c) Actual Speed and reference speed plotted against time on the same graph:

![](/home/trey/Semester 8/ME131/lab5/deliverables/vel+ref_vs_time.jpg)

#### 1.5

Velocity vs. Time plotted with the reference velocity on the real vehicle:

![](/home/trey/Semester 8/ME131/lab5/deliverables/vel_real.png)

#### 1.6

Successful maintenance of speed from flat to inclined surface demonstrated by the cruise controller: 

​	https://drive.google.com/open?id=1HGZ34ErBhhJwNkylFwG9dMojYbjcXJuD

#### 1.7

On the vehicle:
$$
k_p = 70\\
k_i = 1
$$
The control parameters we calculated in Simulink because we employed a very simple first order model for our drivetrain in Simulink. It is unlikely that our battery, ESC, motor, and longitudinal vehicle dynamics for acceleration and braking and be accurately captured using a first order system. With a higher fidelity model for acceleration and braking, the gains calculated from simulation would more closely match the gains chosen on the vehicle.