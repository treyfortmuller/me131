%% Vehicle dynamics simulator
% ===============================
% AUTHOR: Francesco Borrelli, Tony Zheng 
% UPDATED 4/1/2019

clc
clear
close all

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Load BARC vehicle signals during a maneuver
load alldata

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ****** Deliverable 1*****
%% Define Rotation matrices
Ryaw = @(yaw) [cos(yaw), -sin(yaw), 0;
               sin(yaw), cos(yaw),  0;
               0,        0,         1];

Rpitch = @(pitch) [cos(pitch),  0, sin(pitch);
                   0,           1, 0;
                   -sin(pitch), 0, cos(pitch)];

Rroll = @(roll) [1, 0,         0;
                 0, cos(roll), -sin(roll);
                 0, sin(roll), cos(roll)];

% Hint use Ryaw,Rpitch,Rroll to find Q rather than writing the entire matrix 
Q_BtoI = @(yaw,pitch,roll) Rroll(roll)*Rpitch(pitch)*Ryaw(yaw);
Q_Ito_B = @(yaw,pitch,roll) inv(Q_BtoI(yaw, pitch, roll));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% load vehicle_states
latitude_data = sig{1,17}.Data-sig{1,17}.Data(1);
longitude_data = sig{1,16}.Data-sig{1,16}.Data(1);
altitude_data = sig{1,18}.Data-sig{1,18}.Data(1);
pre_center = [latitude_data(1),longitude_data(1)];
% convert to flat earth model
local_output = lla2flat([latitude_data, longitude_data, altitude_data], pre_center,sig{3}.Data(1)*180/pi-90,altitude_data(1));
X = local_output(:,2);
Y= local_output(:,1);
Z = local_output(:,3);
yaw_data=(sig{3}.Data-sig{3}.Data(1));
pitch_data=(sig{2}.Data-sig{2}.Data(1));
roll_data=(sig{1}.Data-sig{1}.Data(1));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Smooth Data and generate X,Y,Z
sw=10; %smoothing window
wx=movmean(sig{4}.Data,sw);
wy=movmean(sig{5}.Data,sw);
wz=movmean(sig{6}.Data,sw);
ax=movmean(sig{7}.Data,sw);
ay=movmean(sig{8}.Data,sw);
az=movmean(sig{9}.Data,sw);

Xsig=timeseries(X,sig{17}.Time); % make a time series
Ysig=timeseries(Y,sig{17}.Time);% make a time series
Zsig=timeseries(Z,sig{17}.Time);% make a time series
Xresampled=resample(Xsig, sig{1}.Time,'linear');
Yresampled=resample(Ysig, sig{1}.Time,'linear');
Zresampled=resample(Zsig, sig{1}.Time,'linear');
vx_I_signal=ts_derivative(Xresampled);
vy_I_signal=ts_derivative(Yresampled);
vz_I_signal=ts_derivative(Zresampled);
vx_I_data=vx_I_signal.Data;
vy_I_data=vy_I_signal.Data;
vz_I_data=vz_I_signal.Data;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Convert vehicle spped from inertial frame to body frame
for k=1:length(vx_I_data)
    Q1c = Q_BtoI(yaw_data(k),pitch_data(k),roll_data(k));
    %Q1c=[cos(yaw_data(k)), -sin(yaw_data(k)),0;sin(yaw_data(k)), cos(yaw_data(k)),0;0,0,1]; % change of frame
    out=Q1c'*[vx_I_data(k);vy_I_data(k);vz_I_data(k)];
    vx_B_data(k,1)=out(1);
    vy_B_data(k,1)=out(2);
    vz_B_data(k,1)=out(3);
end
tSpan = 86400*(sig{1}.Time-sig{1}.Time(1));



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Assume you have angular velocities (measured with the IMU gyros)
% Let's reconstruct the Euler angles with the approach I presented in class
% and compare with Euler angles provided by the IMU software

%% ****** Deliverable 2*****
%% Modify the odeEuler.m script so you can obtain the Euler angles
E0 =[0;0;0];
[t,E] = ode45(@(t,E) odeEuler(t,E,wx,wy,wz,tSpan),tSpan,E0);
figure
plot(t,E,'--')
hold on
plot(tSpan,yaw_data,tSpan,pitch_data,tSpan,roll_data)
legend('Yaw_{sim}','Pitch_{sim}','Roll_{sim}','Yaw_{meas}','Pitch_{meas}','Roll_{meas}','Location','best')
title('Euler Angles')
xlabel('Time (s)')
ylabel('Angle (rad)')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Assume you have angular velocities (measured with the IMU gyros)
% and linear accelerations (measured with the IMU accelerometers)
% Let's reconstruct the vehicle speeds by using Linear momentum consevation
% law and compare them with the speed computed with the GPS

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ****** Deliverable 3*****
%% Modify the odevB.m script so you can obtain linear velocities in the body frame.

vB0 = [0;0;0];
[t,v] = ode45(@(t,v) odevB(t,v,E,ax,ay,az,wx,wy,wz,tSpan,Q_BtoI),tSpan,vB0);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ****** Deliverable 4*****
%% Explain  the discrepancies between the simulated and GPS linear velocities
figure
plot(t,v(:,1),'r--',t,v(:,2),'b--',t,v(:,3),'g--',tSpan,vx_B_data,'r-',tSpan,vy_B_data,'b-',tSpan,vz_B_data,'g-')
title('v in Inertial Frame')
xlabel('Time (s)')
ylabel('v')
legend('vx_{sim}','vy_{sim}','vz_{sim}','vx_{meas}','vy_{meas}','vz_{meas}','Location','best')




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Assume you have the reconstructed linear velocities (v) of the vehicle
% and the reconstructed Euler angles (E), reconstruct vehicle position
% (X,Y,Z) w.r.t inertial frame and and compare it with the GPS position

%% ****** Deliverable 5*****
%% Modify the odeIB.m script so you can obtain the X-Y-Z coordinates in the inertial frame
IB0 = [0;0;0];
figure
[t,IB] = ode45(@(t,IB) odeIB(t,E,v(:,1),v(:,2),v(:,3),tSpan,Q_BtoI),tSpan,IB0);
plot(IB(:,1),IB(:,2),Xresampled.Data,Yresampled.Data)
title('X vs Y')
xlabel('X')
ylabel('Y')
legend('Simulated','GPS','Location','Best')


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% HERE BELOW SOME PLOTS AND MOVIE FOR YOUR AMUSEMENT
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Simulation comparison of the GPS/IMU captured data and your simulated results
l=.2;
w=.4;
h=.2;
figure
hold on
b_exp = [IB(1,1),IB(1,2),IB(1,3)];
rot_exp = Q_BtoI(E(1,1),E(1,2),E(1,3)) ;

x1=0;
x2=20;
y1=-15;
y2=5;
z1=-5;
z2=16;
xlim([x1 x2]);
ylim([y1 y2]);
zlim([z1 z2]);
xlabel('x'); 
ylabel('y'); 
zlabel('z');

az=0;el=90;%topview
%az=90;el=0;%sideview facing 
%az=180;el=0;%sideview facing 
%az=45;el=45;%angledview
%view(az,el);
nframe=10;
for i = 1:nframe:numel(tSpan)
    plot(NaN,NaN,'r',NaN,NaN,'g')
    hold on
    % Draw the BARC based on real data
    b_exp = [Xresampled.Data(i);Yresampled.Data(i);Zresampled.Data(i)];
    rot_exp = Q_BtoI(yaw_data(i),pitch_data(i),roll_data(i));
    drawBox(l,w,h,b_exp,rot_exp,'r');
    
    % Draw the BARC based on simulation results
    b_sim = [IB(i,1);IB(i,2);IB(i,3)];
    rot_sim = Q_BtoI(E(i,1),E(i,2),E(i,3));
    drawBox(l,w,h,b_sim,rot_sim,'g');
    
    xlim([x1 x2]);
    ylim([y1 y2]);
    zlim([z1 z2]);
    xlabel('x'); 
    ylabel('y'); 
    zlabel('z');
    view(az,el);
    plot3(IB(1:i,1),IB(1:i,2),IB(1:i,3));
    plot3(Xresampled.Data(1:i),Yresampled.Data(1:i),Zresampled.Data(1:i))
    
    legend('Red - Experiment','Green - Simulation','Location','Best')
    hold off
    Mov(i) = getframe(gcf);
end
v = VideoWriter('VehicleDynamics_TopView.avi');

%Use this to save the video but set nframe=1
%open(v)
%writeVideo(v,Mov) 
%close(v)
