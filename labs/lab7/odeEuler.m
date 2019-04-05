% This function contains the ODEs for the Euler angles, relative to the
% inertial frame, but expressed along the body-fixed frame basis vectors

function dEuler = odeEuler(t,E,wx,wy,wz,tSpan)
wx = interp1(tSpan,wx,t);
wy = interp1(tSpan,wy,t);
wz = interp1(tSpan,wz,t);

%% ****** Deliverable *****
%% Complete the following term for the inverse Wronskian matrix 
Winv =  ...;

%dEuler is a 3x1 vector containing the derivatives of yaw,pitch,roll 
dEuler = ...;
end
