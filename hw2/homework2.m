% ME131 Homework 2
% Trey Fortmuller

%% 1.1

% controller gains
kp = 2;
ki = 3;

% transfer functions
P = tf([1], [1, -1]) % plant
C = tf([kp, ki], [1, 0]) % controller

% closed loop TF
sys_cl = feedback(P*C, 1)
