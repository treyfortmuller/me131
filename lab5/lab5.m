%% Lab5 Task 3

clear; clc; close all

% acceleration
a = -0.0943;
b = 0.0001;

% braking
% a = -0.2018;
% b = -0.0003275;

wn = 1.8; % desired natural frequency
z = 1.5; % desired damping ratio

dt = 0.02;

% from solving the second order system using the CLTF
kp = (2 * z * wn + a)/b;
ki = (wn^2)/b;

% convert our PI controller to discrete time
cont_ctrl = tf([kp ki], [1 0]);
disc_ctrl = c2d(cont_ctrl, dt);

% convert the continuous plant model to discrete time
cont_plant = tf([b] ,[1 -a]);
disc_plant = c2d(cont_plant, dt);

% run the simulink model
sim('lab5.slx');

plot(vel_scope);









