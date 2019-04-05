% run solns to ME131 HW5

clc; close all;

% plot performance with traction control on
load('tireForceModel.mat');
run('parameter.m');

% load in new parameters to support the full longitudinal dynamics
% theta = pi/6; % a 30 degree incline
theta = 0.0872665; % 10% grade incline

Cd = 0.24;
Af = 1.6 + 0.00056*(m-765); % an approximation for road cars
rho = 1.225; % density of air at STP
V_wind = 0;
g = 9.81;


sim('ABS.slx');

figure()
hold on
plot(sim_v_x);
plot(sim_re_ww)
plot(sim_r_des)

legend('V_x', 'measured wheel speed', 'desired wheel speed')

% save off the vehicle speed in the traction control on state
sim_ON = sim_v_x;

% plot performance with no traction control
load('tireForceModel.mat');
run('parameter.m');
sim('NoABS.slx');

figure()
hold on
plot(sim_v_x);
plot(sim_re_ww)
plot(sim_r_des)

legend('V_x', 'measured wheel speed', 'desired wheel speed')

% plot the velocity profile comparison
figure()
hold on
plot(sim_ON)
plot(sim_v_x)

legend('ABS ON', 'ABS OFF')



