% ME131 Lab6
% determining Cd and Rx for the BARC using least squares
% experimental data in coast_down.mat

%% constants and load data

% note this data has been pruned by hand to only include time at V_0 until
% stopping time T

% laod data
load('coast_down_data.mat')

% run nonlinear least squares to get a beta estimate for each trial
beta_hat1 = run_lsq(coasttrial1.rosbagTimestamp, coasttrial1.data)
beta_hat3 = run_lsq(coasttrial3.rosbagTimestamp, coasttrial3.data)
% beta_hat2 was negative, we'll ingnore it
beta_hat4 = run_lsq(coasttrial4.rosbagTimestamp, coasttrial4.data)
beta_hat5 = run_lsq(coasttrial5.rosbagTimestamp, coasttrial5.data)

% compute an average beta across all 5 trials
beta_hat = (beta_hat1 + beta_hat3 + beta_hat4 + beta_hat5)/4

% compute Cd and Rx in terms of the average beta (using that v(T) = 0)
Cd = (2*m*beta_hat*atan(beta_hat))/(V0*rho*T*Af)
Rx = (V0*m*atan(beta_hat))/(beta_hat*T)

% the plot for task 2.3 deliverable
plot(normalized_t, normalized_v)
title("Normalized Coast Down \beta = " + beta_hat)
ylabel("v(t)/V_{0}")
xlabel("t/T")
grid()

% results
% beta_hat = 0.9439
% Cd = 24.6729 
% Rx = 2.8834





    















