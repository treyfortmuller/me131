% run solns to ME131 HW5

clc; close all;

% plot performance with traction control on
load('tireForceModel.mat');
run('parameter.m');
sim('tractionControlSystem.slx');

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
sim('NoTractionControl.slx');

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

legend('traction control ON', 'traction control OFF')



