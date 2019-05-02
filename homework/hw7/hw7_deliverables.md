# ME131 Homework 7 Deliverables

Trey Fortmuller - 26037758

### Problem 1: Lanekeeping, Stability, and Transient Response

1.1

```matlab
function A_cl = cl_dynamics(Ux, kp, x_LA, vars)
% returns the closed loop lateral vehicle dynamics matrix A-BK for driving
% in a lane given the longitudinal velocity Ux, proportional gain kp and
% lookahead distance x_LA

c0 = vars(1);
c1 = vars(2);
c2 = vars(3);

Iz = vars(4);
Cf = vars(5);
m = vars(6);
a = vars(7);

A22 = -c0 / (m*Ux);
A23 = c0 / m;
A24 = -c1 / (m*Ux);

A42 = -c1 / (Iz*Ux);
A43 = c1 / Iz;
A44 = -c2 / (Iz*Ux);

A = [0, 1,   0,   0;
     0, A22, A23, A24;
     0, 0,   0,   1;
     0, A42, A43, A44];
 
B = [0; Cf / m; 0; (a*Cf)/Iz];

K = [kp, 0, kp*x_LA, 0];

A_cl = A - (B*K);

end
```

Open loop poles for different velocities

![](/home/trey/Dev/me131/homework/hw7/deliverables/prob1/open_loop_poles.jpg)

The poles for both velocities are the same.

1.2

(a) Proportional feedback closed loop poles with no lookahead for various velocities

![](/home/trey/Dev/me131/homework/hw7/deliverables/prob1/cl_no_lookahead.jpg)

(b) The proportional controller, despite having a strong gain, does not move the poles associated with the error states far from the origin. The system is stable for speeds 5 m/s and 10 m/s, there are poles in the right half plane starting at 15 m/s.

1.3

(a) Closed loop poles with lookahead for various lookahead distances

![](/home/trey/Dev/me131/homework/hw7/deliverables/prob1/cl_lookahead.jpg)

(b) Movement of the closed loop poles for lookahead distances between 20 and 100 meters

![](/home/trey/Dev/me131/homework/hw7/deliverables/prob1/cl_lookahead_pole_movement.jpg)

The error state poles split at the real axis and one pole moves farther left (slowing down the error dynamics considerably) and one moves closer to the origin while remaining stable. The vehicle dynamics poles stay in the left half plane but move closer to the right half plane while their imaginary value increases. Qualitatively, this means that the vehicle dynamics become more oscillatory and the error dynamics lose their oscillatory quality which makes sense given that the lookahead distance is increasing.



### Problem 2: Path Tracking

2.1 P-controller with no lookahead

```matlab
% get current curvature value
K(i) = interp1(path.s, path.K, s(i));

% compute control inputs and drag/rolling resistance
% 2.1
deltaFB(i) = -kp*e(i);
deltaFFW(i) = 0;

delta(i) = deltaFB(i)+deltaFFW(i);
```

Lateral error and heading error as functions of time around an oval track

![](/home/trey/Dev/me131/homework/hw7/deliverables/prob2/p_ctrl_no_lookahead.jpg)

2.1 P-controller with lookahead

```matlab
% get current curvature value
K(i) = interp1(path.s, path.K, s(i));

% compute control inputs and drag/rolling resistance
% 2.2
deltaFB(i) = -kp*(e(i) + xLA*dPsi(i));
deltaFFW(i) = 0;

delta(i) = deltaFB(i)+deltaFFW(i);
```

Lateral error and heading error as functions of time around an oval track

![](/home/trey/Dev/me131/homework/hw7/deliverables/prob2/p_ctrl_lookahead.jpg)

This improved the tracking performance on both the lateral deviation and heading error states as expected, but lateral errors are still large compared to the length of the vehicle. Note these plots do not have normalized y-axes, these errors are in fact much smaller than those shown in the plot of errors without using a lookahead.

2.1 P-controller with lookahead and feedforward

```matlab
% get current curvature value
K(i) = interp1(path.s, path.K, s(i));

% compute control inputs and drag/rolling resistance
% 2.3
betaSS(i) = (b - ((a*m*(Ux^2))/(Cr*L)))*K(i);
deltaFB(i) = -kp*(e(i) + xLA*(dPsi(i)*betaSS(i)));
deltaFFW(i) = L*K(i) + Kug*(Ux^2)*K(i);

delta(i) = deltaFB(i)+deltaFFW(i);
```

Lateral error and heading error as functions of time around an oval track

![](/home/trey/Dev/me131/homework/hw7/deliverables/prob2/p_ctrl_lookahead_with_ffw.jpg)

Errors in the lateral deviation are brought down to below one meter in either direction which is a significant improvement over the other two control strategies. With some gain scheduling based on velocity, this control approach may be usable on a real vehicle.

### Problem 3: Electronic Stability Control

 3.1 

Matlab output from the reference generator for various steering angles

```
yawRateRef1, vyRef1 = 0.28805, 0.13565
yawRateRef2, vyRef2 = 0.62539, 0.93745
```
