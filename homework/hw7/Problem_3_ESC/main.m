clear all
close all
clc

global cellFxAlpha_front cellFxAlpha_rear cellFySigma_front cellFySigma_rear
global g m L l_f l_r C_f C_r mue dt I_z W 

%% (1) Load Vehicle Parameters
load('tireModel.mat') % combined tire model
m = 2237; % vehicle mass (kg)
W = 1.720; % width
L = 3.020; % wheelbase
g = 9.81; % gravity acceleration (m/s^2)
mue = 0.6; % road friction coefficient
l_f = 1.8; % distance between c.g. and front axle (m)
C_f = 5.9563e+04; % front tire cornering stiffness (N/rad)
C_r = 8.8998e+04; % rear tire cornering stiffness (N/rad)
l_r = L - l_f; % distance between c.g. and rear axle (m)
% m_f = m/L*l_r; % vehicle front mass (kg)
% m_r = m/L*l_f; % vehicle rear mass (kg)
I_z = 5550.045; % yaw moment of inertia
dt = 0.01;                     % sampling rate
Tf = 4;                        % End of integration
time = 0:dt:Tf;                % Integration interval

%% (2) Compute driver steering input
mag = 14*pi/180; % Driver's steering input magnitude
Tfsteer = 0.3; % Driver's steering input final time
steerT = 0:dt:Tfsteer;
deltaF = mag*ones(1,length(time));
deltaF(1:length(steerT)) = mag/2-mag/2*cos(pi/Tfsteer*steerT);

%% (3) Reference Test
[yawRateRef1, vyRef1] = referenceGen(5*pi/180,10);
[yawRateRef2, vyRef2] = referenceGen(30*pi/180,8);
disp(['yawRateRef1, vyRef1 = ', num2str(yawRateRef1), ', ' num2str(vyRef1)])
disp(['yawRateRef2, vyRef2 = ', num2str(yawRateRef2), ', ' num2str(vyRef2)])

%% (4) Set Initial Conditions
clc; close all;

vx = 10; vy = 0; yaw = pi/2; yawRate = 0; X = 0; Y = 0;
x0 = [vx vy yaw yawRate X Y];
yawRateRef_ESC = zeros(1,length(time));
vyRef_ESC = zeros(1,length(time));
xESC = zeros(6,length(time)+1);
xNoESC = zeros(6,length(time)+1);
xESC(:,1) = x0';
xNoESC(:,1) = x0';

% slip angles
alpha_r_NoESC = zeros(1,length(time));
alpha_f_NoESC = zeros(1,length(time));

alpha_r_ESC = zeros(1,length(time));
alpha_f_ESC = zeros(1,length(time));

% %% (5) Run Simulations with ESC OFF
for i = 1:length(time)
    %read current state
    vx_NoESC = xNoESC(1,i);
    vy_NoESC = xNoESC(2,i);
    yaw_NoESC = xNoESC(3,i);
    yawRate_NoESC = xNoESC(4,i);
    X_NoESC = xNoESC(5,i);
    Y_NoESC = xNoESC(6,i);
    
    % Reference generator
    [yawRateRef_NoESC(i), vyRef_NoESC(i)] = referenceGen(deltaF(i),vx_NoESC);
    
    % Simulation
    xNoESC(:,i+1) = vehicleDyn(xNoESC(:,i),deltaF(i),0,0,0,0);
    
    alpha_r_NoESC(i) = -atan(vy_NoESC / vx_NoESC);
    alpha_f_NoESC(i) = deltaF(i) - atan(vy_NoESC / vx_NoESC);

end


% %% (6) Run Close-Loop Simulations with ESC ON
for i = 1:length(time)
    %read current state
    vx = xESC(1,i);
    vy = xESC(2,i);
    yaw = xESC(3,i);
    yawRate = xESC(4,i);
    X = xESC(5,i);
    Y = xESC(6,i);
    
    % Reference generator
    [yawRateRef_ESC(i), vyRef_ESC(i)] = referenceGen(deltaF(i),vx);
    
    % Discrete-time LQR controller
    Mz = ESCdlqr(yawRateRef_ESC(i),vyRef_ESC(i),yawRate,vy,vx);
    
    % Braking logic
    [Fxlf, Fxlr, Fxrf, Fxrr] = brakingLogic(Mz,vx,vy,yawRate,deltaF(i));

    % Simulation
    xESC(:,i+1) = vehicleDyn(xESC(:,i),deltaF(i),Fxlf,Fxlr,Fxrf,Fxrr);
    
    alpha_r_ESC(i) = -atan(vy / vx);
    alpha_f_ESC(i) = deltaF(i) - atan(vy / vx);

end

%% (7) Plot Routines 
figure (1)
subplot(2,1,1)
plot(time,xESC(2,1:end-1),'Linewidth', 2)
hold on
plot(time,vyRef_ESC(1:end),'--','Linewidth', 2)
plot(time,xNoESC(2,1:end-1))
plot(time,vyRef_NoESC(1:end),'--')
hold off
xlabel('time (sec)')
ylabel('v_y (m/s)')
legend('v_y (ESC on)','v_y ref (ESC on)', 'v_y (ESC off)','v_y ref (ESC off)')
legend('Location','southeast')
subplot(2,1,2)
plot(time,xESC(4,1:end-1),'Linewidth', 2)
hold on
plot(time,yawRateRef_ESC(1:end),'--','Linewidth', 2)
plot(time,xNoESC(4,1:end-1))
plot(time,yawRateRef_NoESC(1:end),'--')
xlabel('time (sec)')
ylabel('yaw rate (rad/s)')
legend('yaw rate (ESC on)','yaw rate ref (ESC on)', 'yaw rate (ESC off)','yaw rate ref (ESC off)')
legend('Location','southeast')

figure (2)
plot(xESC(5,:),xESC(6,:))
hold on
plot(xNoESC(5,:),xNoESC(6,:))
plot([xESC(5,1)+l_f*cos(xESC(3,1)), xESC(5,1)-l_r*cos(xESC(3,1))],...
    [xESC(6,1)+l_f*sin(xESC(3,1)),xESC(6,1)-l_r*sin(xESC(3,1))],'c','LineWidth',2)
plot([xESC(5,end)+l_f*cos(xESC(3,end)), xESC(5,end)-l_r*cos(xESC(3,end))],...
    [xESC(6,end)+l_f*sin(xESC(3,end)),xESC(6,end)-l_r*sin(xESC(3,end))],'c','LineWidth',2)
plot([xNoESC(5,end)+l_f*cos(xNoESC(3,end)), xNoESC(5,end)-l_r*cos(xNoESC(3,end))],...
    [xNoESC(6,end)+l_f*sin(xNoESC(3,end)),xNoESC(6,end)-l_r*sin(xNoESC(3,end))],'c','LineWidth',2)
xlabel('X (m)');
ylabel('Y (m)');
legend('Traj. with ESC on','Traj. with ESC off')

figure (3)
plot(time,xESC(3,1:end-1)*180/pi)
hold on
plot(time,xNoESC(3,1:end-1)*180/pi)
xlabel('time (sec)')
ylabel('yaw (deg)')
legend('yaw with ESC on(deg)','yaw with ESC off(deg)')
legend('Location','southeast')

%% Plotting slip angles for ESC on and off
figure (4)
hold on
plot(time, alpha_r_NoESC)
plot(time, alpha_f_NoESC)
plot(time, alpha_r_ESC)
plot(time, alpha_f_ESC)

xlabel('time (sec)')
ylabel('slip angles (rad)')
legend('No ESC: rear slip angle','No ESC: front slip angle', 'ESC: rear slip angle', 'ESC: front slip angle')
