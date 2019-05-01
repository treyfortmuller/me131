function [Fxlf, Fxlr, Fxrf, Fxrr] = brakingLogic(Mz,vx,vy,yawRate,deltaF)

global l_f l_r W
alphaF = deltaF-atan((vy+l_f*yawRate)/vx);
alphaR = -atan((vy-l_r*yawRate)/vx);

if Mz == 0
    Fxlf = 0;
    Fxlr = 0;
    Fxrf = 0;
    Fxrr = 0;
elseif Mz > 0
    if abs(alphaF)-abs(alphaR) > 0 
        Fxlf = 0;
        Fxlr = -2*abs(Mz)/W;
        Fxrf = 0;
        Fxrr = 0;
    else 
        Fxlf = -abs(Mz)/sin(atan(W/2/l_f)-deltaF)/sqrt(l_f^2+(W/2)^2);
        Fxlr = 0;
        Fxrf = 0;
        Fxrr = 0;
    end
else
    if abs(alphaF)-abs(alphaR) > 0 
        Fxlf = 0;
        Fxlr = 0;
        Fxrf = 0;
        Fxrr = -2*abs(Mz)/W;
    else 
        Fxlf = 0;
        Fxlr = 0;
        Fxrf = -abs(Mz)/sin(deltaF+atan(W/2/l_f))/sqrt(l_f^2+(W/2)^2);
        Fxrr = 0;
    end
end
        
