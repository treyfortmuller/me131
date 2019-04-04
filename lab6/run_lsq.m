function beta_hat = run_lsq(time_nsecs,velocity)
% returns from beta_hat from a nonlinear least squares on recorded coast
% down data

% constants
Af = 0.15*0.25*0.9; % approximate frontal area from NSCEP
rho = 1.225; % air density
g = 9.81; % gravitational acceleration
m = 5; % mass

% normalize the unix epoch to elapsed seconds
time_s = [];

for i=1:length(time_nsecs)
    time_s = [time_s; (time_nsecs(i)-time_nsecs(1))*10^-9];
end

V0 = velocity(1); % initial velocity in [m/s]
T = time_s(end); % the time the vehicle comes to rest in [s]

normalized_t = time_s./T;
normalized_v = velocity./V0;

xdata = normalized_t;
ydata = normalized_v;

% an initial guess of the beta
beta = 1;

% the function to fit to
fun = @(beta, xdata) (1/beta)*tan((1 - xdata)*atan(beta));

% the least squares solution to the beta parameter
beta_hat = lsqcurvefit(fun, beta, xdata, ydata);
end

