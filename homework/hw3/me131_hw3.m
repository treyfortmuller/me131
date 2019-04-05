% ME131 HW3
% Trey Fortmuller
% experimental data in straightLineTest.mat

%% prob. 2.1

% Vx never hits zero so we use the full length of the array

T = t(length(t))
plot(t / T, Vx / Vx(1))

%% prob 2.2

xdata = t / t(length(t));
ydata = Vx / Vx(1);

% an initial guess of the beta
beta = 1;

% the function to fit to
fun = @(beta, xdata) (1/beta)*tan((1 - xdata)*atan(beta));

% the least squares solution to the beta parameter
beta_hat = lsqcurvefit(fun, beta, xdata, ydata)

Vx(1) % intitial velocity

%% prob 4.1
% use the upNdownTest data to construct a Y matrix by approximating accel

% the velocity at every time step
plot(v1);

% obtain an acceleration array
a = [];

for i = 1:length(v1)
    
    if (i+1) <= length(v1)
        accel = (v1(i+1) - v1(i)) / dt;
        a = [a; accel]; 
    end
     
end

size(a)
Y = a; % the Y matrix

%% prob 4.2

% construct the 3 column matrix X using v1, v2
% we get rid of the last value in the v1 array to match the length(a)

v1_fix = v1(1:length(v1)-1);
v1_fix_square = v1_fix.^2;

length(v1_fix_square); % same as length(a)

% second and third columns of X mtx
one = ones(length(v1_fix), 1);
minus_one = -1 * ones(length(v1_fix), 1);

% construct the X matrix
X = [v1_fix_square, one, minus_one];

%% prob 4.3

% performing the linear least squares

% check sizes
size(X)
size(Y)

w = inv(X'*X)*X'*Y






    















