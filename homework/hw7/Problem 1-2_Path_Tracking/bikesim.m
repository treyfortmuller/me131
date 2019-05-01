%Simulates a constant speed, constant steer input maneuver given a
%specified tire model and the steer angle input, in rad

function [t, e, dPsi, r, Uy] = bikesim(Ux, kp, xLA, tiremodel)

% Define your vehicle parameters here
Wf = .57;
m = 1650; %mass, in kg
Cf = 200000; %Front cornering stiffness, N/rad
Cr = 200000; %Rear cornering stiffness, N/rad
L = 2.468; %Vehicle length, meters
a = (1-Wf)*L; %Distance from CG to front, m
b = Wf*L; %Distance from CG to rear, m
Iz = 2235; %Vehicle rotational inertia, kg m^2
g = 9.81;  %gravity acceleration, meters/sec^2
FzF = m*b*g/L; %Normal force on front tire
FzR = m*a*g/L; %Normal force on rear tire
%muPf = 1; muSf = .8; %Peak and sliding friction coefficents, front tire
muPf = 1.2; muSf = 1; 
muPr = 1.1; muSr = .9; %Peak and sliding friction coefficents, rear tire


% Allocate memory for the important vectors
% This makes your run time much faster

tstep = .001; 
t = 0:tstep:10;
N = length(t);
Uy = zeros(N,1);
r = zeros(N,1);
e = zeros(N,1);
dPsi = zeros(N,1);
alphaF = zeros(N,1);
alphaR = zeros(N,1);
FyF = zeros(N,1);
FyR = zeros(N,1);

% Define your initial conditions

Uy(1) = 0;
r(1) = 0;
e(1) = .5;
dPsi(1) = 0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simulation loop 
% Run through the equations of motion
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

for i = 1:N-1,
    
    % Solve for alphaf, alphar given Ux(i), delta, r and Uy
    delta = -kp*(e(i) + xLA*dPsi(i));
    
    alphaF(i) = (Uy(i) + a*r(i))/Ux - delta;
    alphaR(i) = (Uy(i) - b*r(i))/Ux;
    
    % Solve for FyF and FyR
    
    if strcmp(tiremodel,'lin')
        FyF(i) = -Cf*alphaF(i); %Note: Assuming Linear Tire Model;
        FyR(i) = -Cr*alphaR(i);
    elseif strcmp(tiremodel,'nonlin')
        FyF(i) = tireforces(Cf, muPf, muSf, alphaF(i), FzF);
        FyR(i) = tireforces(Cr, muPr, muSr, alphaR(i), FzR);
    else
        error('Specify lin or nonlin')
    end
    
    % Solve for derivatives drdt dUydt
    drdt   = (a*FyF(i) - b*FyR(i))/Iz;
    dUydt  = (FyF(i)+FyR(i))/m-Ux*r(i);
    dedt     = Uy(i) + Ux*dPsi(i);
    dPsidt = r(i);
    
    % Update time and states
    Uy(i+1) = Uy(i) + tstep*dUydt;
    r(i+1)  =  r(i) + tstep*drdt;
    e(i+1) =   e(i) + tstep*dedt;
    dPsi(i+1) = dPsi(i) + tstep*dPsidt;
end

end
    
    
