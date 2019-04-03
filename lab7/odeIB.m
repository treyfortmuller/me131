% This function contains the ODEs for the body-fixed frame basis vectors

function dIB = odeIB(t,E,vx,vy,vz,tSpan,Q_BtoI)
yaw = interp1(tSpan,E(:,1),t);
pitch = interp1(tSpan,E(:,2),t);
roll = interp1(tSpan,E(:,3),t);
vx = interp1(tSpan,vx,t);
vy = interp1(tSpan,vy,t);
vz = interp1(tSpan,vz,t);

%% ****** Deliverable *****
%% Complete the ODE for x-y-z coordinates in the inertial frame
%dIB is a 3x1 vector containing the derivatives of X, Y, Z 
dIB = ...;
    
end
