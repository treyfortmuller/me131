clear all
close all
clc

load('Sensor_data.mat')
%% Vehicle Parameters 
m = 1830.59;
Lf = 1.15214;     
Lr = 1.69286;
L = Lf+Lr;
Iz = 3477;
dt = 0.001;
Cf = 48703;
Cr = 57269;
%% Initial Conditions
X0 = 49.41;
Y0 = 49.33807;
yaw0 = 3.930132;
Vx0 = 11.901;
Vy0 = 0;
yawRate0 = 0;
%%
sim('ME131_lab8.slx')

%%
figure
scatter(x_pos_dynamic.Data(1),y_pos_dynamic.Data(1))
hold on
plot(x_pos_kinematic.Data,y_pos_kinematic.Data,'r')
plot(GPS_X,GPS_Y,'k--')
legend('Start','Kinematic Model Trajectory','True Trajectory','Location','Northwest')
title('Kinematic Bicycle Model')
xlabel('X [m]')
ylabel('Y [m]')

figure
scatter(x_pos_dynamic.Data(1),y_pos_dynamic.Data(1))
hold on
plot(x_pos_dynamic.Data,y_pos_dynamic.Data,'blue')
plot(GPS_X,GPS_Y,'k--')
legend('Start','Dynamic Model Trajectory','True Trajectory','Location','Northwest')
title('Dynamic Bicycle Model')
xlabel('X [m]')
ylabel('Y [m]')