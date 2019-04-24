# ME131 Lab 8 Deliverables

Trey Fortmuller

1. subsystem 1

   ![](/home/trey/Semester 8/ME131/labs/lab8/deliverables/subsystem1.png)

2. kinematic bicycle model predicted trajectory

   ![](/home/trey/Semester 8/ME131/labs/lab8/deliverables/kinematic.jpg)

3. The kinematic bicycle model is suitable for driving conditions in which there is a very small slip angle. The plot shows that the corners would have been much tighter if the tires did not slip (because the kinematic model does not include tire slippage, it is only based on geometric constraints). 

4. subsystem 2

   ![](/home/trey/Semester 8/ME131/labs/lab8/deliverables/subsystem2.png)

5. dynamic bicycle model predicted trajectory

   ![](/home/trey/Semester 8/ME131/labs/lab8/deliverables/dynamic.jpg)

6. The dynamic model is based on tire forces so it will more accurately capture driving near the limits of the traction. The dynamic model predicts the trajectory well until errors in the IMU are integrated enough to cause drift.
7. The dynamic model outperforms the kinematic model in this case because this trajectory is one in which tire forces are significant, i.e. the slip angle and cornering stiffness are important. If the vehicle were to traverse the same trajectory at a much slower rate, the kinematic model would converge to the dynamic model's prediction.