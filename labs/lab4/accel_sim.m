% a script to simulate the dynamical
% equation for acceleration of the barc

close all; clc;

%% PWM Input Step 1
% simulation time
t1 = linspace(0, 4);
% initial velocity
v01 = 0;
u1 = 1580; % input PWM signal
v1 = ode23(@(t1, v1)accel_dynamics(t1, v1, u1), t1, v01); % simulate the ODE

time1 = v1.x;
velocity1 = v1.y;

%% PWM Input Step 2
t2 = linspace(4, 6);
% intial velocity is the final velocity of the previous step
v02 = velocity1(end);
u2 = 1620; % input PWM
v2 = ode23(@(t2, v2)accel_dynamics(t2, v2, u2), t2, v02); % simulate the ODE

time2 = v2.x;
velocity2 = v2.y;

%% PWM Input Step 3
% simulation time
t3 = linspace(6, 8);
% initial velocity
v03 = velocity2(end);
u3 = 1600; % input PWM signal
v3 = ode23(@(t3, v3)accel_dynamics(t3, v3, u3), t3, v03); % simulate the ODE

time3 = v3.x;
velocity3 = v3.y;

%% PWM Input Step 4
t4 = linspace(8, 10);
% intial velocity is the final velocity of the previous step
v04 = velocity3(end);
u4 = 1500; % input PWM
v4 = ode23(@(t4, v4)accel_dynamics(t4, v4, u4), t4, v04); % simulate the ODE

time4 = v4.x;
velocity4 = v4.y;

%% Plot all steps output
figure()
legend()
hold on
plot(time1, velocity1)
plot(time2, velocity2)
plot(time3, velocity3)
plot(time4, velocity4)

% from the lab4 test script:
plot(rec_realTime, smooth_vel);





