% ME131 Lab6
% determining Cd and Rx for the BARC using least squares
% experimental data in coast_down.mat

close all; clear; clc;

% constants
Af = 0.15*0.25*0.9; % approximate frontal area from NSCEP
rho = 1.225; % air density
g = 9.81; % gravitational acceleration
m = 5; % mass

% note this data has been pruned by hand to only include time at V_0 until
% stopping time T

% laod data
load('coast_down_data.mat')

hold on;

% run nonlinear least squares to get a beta estimate for each trial
[beta_hat1, Cd1, Rx1] = run_lsq(coasttrial1.rosbagTimestamp, coasttrial1.data);
% beta_hat2 was negative, we'll ingnore it
[beta_hat3, Cd3, Rx3] = run_lsq(coasttrial3.rosbagTimestamp, coasttrial3.data);
[beta_hat4, Cd4, Rx4] = run_lsq(coasttrial4.rosbagTimestamp, coasttrial4.data);
[beta_hat5, Cd5, Rx5] = run_lsq(coasttrial5.rosbagTimestamp, coasttrial5.data);

% compute an average across all 4 trials
beta_hat = (beta_hat1 + beta_hat3 + beta_hat4 + beta_hat5)/4
Cd_hat = (Cd1 + Cd3 + Cd4 + Cd5)/4
Rx_hat = (Rx1 + Rx3 + Rx4 + Rx5)/4

%% plot the line of best fit using beta_hat

% TODO: this seems janky to me, which normalized time and I supposed to
% use?

time_nsecs = coasttrial1.rosbagTimestamp;
velocity = coasttrial1.data

time_s = [];

for i=1:length(time_nsecs)
    time_s = [time_s; (time_nsecs(i)-time_nsecs(1))*10^-9];
end

V0 = velocity(1); % initial velocity in [m/s]
T = time_s(end); % the time the vehicle comes to rest in [s]

normalized_t = time_s./T;
normalized_v = velocity./V0;

normal_v = (1/beta_hat)*tan((1-normalized_t)*atan(beta_hat));
plot(normalized_t, normal_v, 'g', 'LineWidth', 2)

title("Normalized Coast Down \beta = " + beta_hat)
ylabel("v(t)/V_{0}")
xlabel("t/T")
grid()
legend("trial 1", "trial 3", "trial 4", "trial 5", "best fit")

% results
% beta_hat =
% 
%     0.9439
% 
% 
% Cd_hat =
% 
%    24.9727
% 
% 
% Rx_hat =
% 
%     3.0344


    















