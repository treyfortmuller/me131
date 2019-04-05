close;clear;clc;
%% 1.3
%% 1.4
syms Fx Rx theta mg F_aero p Cd Af vd
mdvdt = Fx - Rx - mg*sin(theta) - 1/2*p*Cd*Af*vd^2;
jacobian(mdvdt,[vd,Fx])

Rx = 3.0334;
Af = 0.15*0.25*0.9;
Cd = 24.9723;
p = 1.225;
g = 9.81;
m = 5;
A = -Af*Cd*p*0.5/m;
B = 1/m;
%% 1.5
K = lqr(A,B,1,1)
%% 1.6 simulink model
K = lqr(A,B,100,1)
sim('LQR_finished.slx')
%% 1.7 
