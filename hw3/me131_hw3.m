% ME131 HW3
% Trey Fortmuller
% experimental data in straightLineTest.mat

%% prob. 2.1

% Vx never hits zero so we use the full length of the array
normalization = 100;

plot(normalization*(t / length(t)), Vx / Vx(1))

%% prob 2.2

xdata = t / length(t);
ydata = Vx / Vx(1);

% an initial guess of the beta
beta = 1;

% the function to fit to
fun = @(beta, xdata) (1/beta)*tan((1 - xdata)*atan(beta));

% the least squares solution to the beta parameter
beta_hat = lsqcurvefit(fun, beta, xdata, ydata)

Vx(1) % intitial velocity
