% This function contains the ODEs for the velocity of the mass center,
% relative to the inertial frame, but expressed along the body-fixed frame
% basis vectors

function dvB = odevB(t,v,E,ax,ay,az,wx,wy,wz,tSpan,Q_BtoI)
yaw = interp1(tSpan,E(:,1),t);
pitch = interp1(tSpan,E(:,2),t);
roll = interp1(tSpan,E(:,3),t);
ax = interp1(tSpan,ax,t);
ay = interp1(tSpan,ay,t);
az = interp1(tSpan,az,t);
wx = interp1(tSpan,wx,t);
wy = interp1(tSpan,wy,t);
wz = interp1(tSpan,wz,t);

g = 9.81;

% v is a 3x1 vector [vx;vy;vz]
% function skew_sym(vector) will come in handy. 

%% ****** Deliverable *****
%% Complete the ODEs for linear velocities in the body frame.
dvB = ...;

end