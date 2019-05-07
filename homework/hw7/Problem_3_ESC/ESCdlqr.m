function Mz = ESCdlqr(yawRateRef,vyRef,yawRate,vy,vx)
% Inputs: 
%    yawRateRef: yaw rate reference in rad/s
%    vyref: lateral velocity reference in m/s
%    yawRate: yaw rate feedback state in rad/s
%    vy: lateral velocity feedback state in m/s
%    vx: longitudinal velocity feedback state in m/s
% Outputs:
%    Mz: yaw moment control signal in N*m
global m l_f l_r C_f C_r dt I_z

a11 = -2*(C_r+C_f)/m/vx;
a12 = -2*(C_f*l_f-C_r*l_r)/m/vx-vx;
a21 = -2*(C_f*l_f-C_r*l_r)/I_z/vx;
a22 = -2*(C_f*l_f^2+C_r*l_r^2)/I_z/vx;

A = [a11, a12; a21, a22];
Ad = A*dt+eye(2);

b11 = 2*C_f/m;
b21 = 2*l_f*C_f/I_z;

c11 = 0;
c21 = 1/I_z;

C = [c11; c21];
Cd = C*dt;

% formulate the error states, our LQR control is based on the error
% dynamics
evy = vy - vyRef;
eyawRate = yawRate - yawRateRef;

e = [evy; eyawRate];

% weighting matrices, Q is weights on the states, R is weights on control
% effort. the states are lateral velocity error and angular rate error
Q = (11^7)*eye(2);
R = (10^-1)*eye(1);

% [K,S,e] = dlqr(A,B,Q,R,N)
[K, S, e] = dlqr(Ad, Cd, Q, R); % LQR controller

% Mz = (10^8)*K*e;
Mz = K*e;