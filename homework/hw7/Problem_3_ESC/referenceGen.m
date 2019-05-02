function [yawRateRef, vyRef] = referenceGen(deltaF,vx)
% Inputs: 
%    deltaF: Steering angle in radiants, 
%    vx: vehicle longitudinal velocity in m/s
% Outputs:
%    yawRateRef: yaw rate reference in rad/s
%    vyref: lateral velocity reference in m/s
global g m L l_f l_r C_f C_r mue 

% implement reference generator according to ESC notes
R = (L + ((m * (vx^2) * (l_r*C_r - l_f*C_f)) / (2*C_r*C_f*L))) / deltaF;

yawRateRef = vx / R;
betaRef = (l_r / R) - ((l_f*m*(vx^2)) / (2*C_r*L*R));

% now we bound our outputs to never exceed the tire's limits
yawRateBound = 0.85*(mue*g / vx)*sign(yawRateRef); % bound on the yaw rate
betaBound = atan(0.02*mue*g)*sign(betaRef); % bound on the slip angle

if yawRateRef >= yawRateBound
    yawRateRef = yawRateBound;
end

if betaRef >= betaBound
    betaRef = betaBound;
end
   
% compute the vyRef from the beta reference
vyRef = betaRef*vx;
