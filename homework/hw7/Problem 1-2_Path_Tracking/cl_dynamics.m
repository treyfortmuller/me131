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

