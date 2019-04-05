function dvdt = accel_dynamics(t, v, u)
% a function to simulate the accerlation dynamics of the barc, solving the
% ODE given in lab4

% constants determined via linear regression in lab4_accel_fit.m
a = -0.0943;
b = 0.0001;

dvdt = a*v + b*u;

end