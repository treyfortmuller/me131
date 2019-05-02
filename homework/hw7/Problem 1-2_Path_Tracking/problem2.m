%Nitin Kapania
%Code for HW 7, Problem 2
clear all; close all; clc;
load oval
%%


Wf = .57;
m = 1650; %mass, in kg
Cf = 200000; %Front cornering stiffness, N/rad
Cr = 200000; %Rear cornering stiffness, N/rad
L = 2.468; %Vehicle lengthgth, meters
a = (1-Wf)*L; %Distance from CG to front, m
b = Wf*L; %Distance from CG to rear, m
Iz = 2235; %Vehicle rotational inertia, kg m^2
g = 9.81;  %gravity acceleration, meters/sec^2
FzF = m*b*g/L; %Normal force on front tire
FzR = m*a*g/L; %Normal force on rear tire
Kug = (FzF/Cf - FzR/Cr)/g;

%controller parameters and velocity
kp  = 1*pi/180; %rad/meter
xLA = 10; %m
Ux = 8;

% Allocate memory for the important vectors
% This makes your run time much faster

tstep = .001; 
t = 0:tstep:27;
N = length(t);
Uy = zeros(N,1);
r = zeros(N,1);
e = zeros(N,1);
s = zeros(N,1);
K = zeros(N,1);
dPsi = zeros(N,1);
alphaF = zeros(N,1);
alphaR = zeros(N,1);
FyF = zeros(N,1);
FyR = zeros(N,1);
delta = zeros(N,1);
deltaFFW = zeros(N,1);
deltaFB = zeros(N,1);
betaSS = zeros(N,1);

% Define your initial conditions

Uy(1) = 0;
r(1) = 0;
e(1) = 0;
dPsi(1) = 0;
s(1) = 0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simulation loop 
% Run through the equations of motion
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

for i = 1:N-1
    
    %get current curvature value
    K(i) = interp1(path.s, path.K, s(i));
    
    %compute control inputs and drag/rolling resistance
    
%     2.1
%     deltaFB(i) = -kp*e(i);
%     deltaFFW(i) = 0;
      
%     2.2
%     deltaFB(i) = -kp*(e(i) + xLA*dPsi(i));
%     deltaFFW(i) = 0;
    
%     2.3
    betaSS(i) = (b - ((a*m*(Ux^2))/(Cr*L)))*K(i);
    deltaFB(i) = -kp*(e(i) + xLA*(dPsi(i)*betaSS(i)));
    deltaFFW(i) = L*K(i) + Kug*(Ux^2)*K(i);
    
    delta(i) = deltaFB(i)+deltaFFW(i);
       
    % Solve for FyF and FyR
    alphaF(i) = (Uy(i) + a*r(i))/Ux - delta(i);
    alphaR(i) = (Uy(i) - b*r(i))/Ux;
    FyF(i) = -Cf*alphaF(i); %Note: Assuming Linear Tire Model;
    FyR(i) = -Cr*alphaR(i);
    
    % Solve for derivatives drdt dUydt
    drdt   = (a*FyF(i) - b*FyR(i))/Iz;
    dUydt  =  (FyF(i)+FyR(i))/m   - Ux*r(i);
    dedt   = Uy(i) + Ux*dPsi(i);
    dsdt   = Ux - Uy(i)*dPsi(i);
    dPsidt = r(i) - dsdt*K(i);
    
    % Update time and states
    Uy(i+1) = Uy(i) + tstep*dUydt;
    r(i+1)  =  r(i) + tstep*drdt;
    e(i+1) =   e(i) + tstep*dedt;
    s(i+1) =   s(i) + tstep*dsdt;
    dPsi(i+1) = dPsi(i) + tstep*dPsidt;
    
%     if s(i) > path.s(end)-2
%         break
%     end
    
end

%% optional
subplot(2, 1, 1)
plot(t, e,'k','LineWidth',2); grid on;
xlim([0 t(end)]);
ylabel('e (m)','FontSize',14)

subplot(2, 1, 2)
plot(t, dPsi*180/pi,'k','LineWidth',2); grid on;
set(gca,'XTickLabel',[])
ylabel('dPsi (deg)','FontSize',14)
xlabel('Time (seconds)','FontSize',14)

% animateSim(e, s, dPsi, delta, path)