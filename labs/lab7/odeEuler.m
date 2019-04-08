% This function contains the ODEs for the Euler angles, relative to the
% inertial frame, but expressed along the body-fixed frame basis vectors

function dEuler = odeEuler(t,E,wx,wy,wz,tSpan)
wx = interp1(tSpan,wx,t);
wy = interp1(tSpan,wy,t);
wz = interp1(tSpan,wz,t);

%% ****** Deliverable *****
%% Complete the following term for the inverse Wronskian matrix 
% psi = yaw
% theta = pitch
% phi = roll

yaw = E(1);
pitch = E(2);
roll = E(3);

Winv =  (1/cos(pitch))*[0, sin(roll), cos(roll);
                        0, cos(roll)*cos(pitch), -sin(roll)*cos(pitch);
                        cos(pitch), sin(roll)*sin(pitch), cos(roll)*sin(pitch)];

angular_vel = [wx; wy; wz];
                    
%dEuler is a 3x1 vector containing the derivatives of yaw,pitch,roll 
dEuler = Winv*angular_vel;
end
