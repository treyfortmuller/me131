%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Problem 1: Parameters for traction control design
%%% ME 131 Vehicle Dynamics and Control
%%% 2016-03-10 by Grace Liao
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

driverDesired = 180; %Nm
m = 1631; %Kg
r_e = 0.35; %m
R = 0.12055;
Je = 0.28; %Kgm^2
tau_f = 0.004;
be = 0.008;
R_w_Idle = 9;
v0 = 0.001; %m/s
w0 = v0/r_e/R;
sigma_max = % Fill with answer from 1.1