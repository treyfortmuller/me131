function animateSim(e, s, dPsi, delta, path)

    %convert e and dPsi into posE, posN, psi;
    close all;
    [posE posN psi] = convertPathToGlobal(path, s, e, dPsi);
    veh.a = 1.05;
    veh.b = 1.4;
    veh.d = 1.55;
    
    figure;    
    F =[]
    for i = 1:100:length(e)
        plotVehicle(posE(i), posN(i), psi(i), delta(i), veh);
        axis equal; grid on;
        xlim( [ posE(i)-10 posE(i)+10 ]);
        ylim( [ posN(i)-10 posN(i)+10 ]);

        hold on;
        plot(path.roadE, path.roadN,'k--','LineWidth',2);
        hold off;

        F = [F getframe(gcf)];
    end
    
    
end

function plotVehicle(posE, posN, psi, delta, veh)
    a = veh.a; b= veh.b; d = 1.5; rW = .34;
    
    
    %Draw line from CG to front axle, CG to rear axle - the "body"
    FrontAxle_Center_x = posE - a*sin(psi);
    FrontAxle_Center_y = posN + a*cos(psi);

    RearAxle_Center_x = posE + b*sin(psi);
    RearAxle_Center_y = posN - b*cos(psi);
    
    FrontBody =  [posE FrontAxle_Center_x; posN FrontAxle_Center_y];
    RearBody  =  [posE RearAxle_Center_x;  posN RearAxle_Center_y];
    
    FrontAxle_Right_x = FrontAxle_Center_x + (d/2)*cos(psi);
    FrontAxle_Right_y = FrontAxle_Center_y + (d/2)*sin(psi);

    FrontAxle_Left_x = FrontAxle_Center_x - (d/2)*cos(psi);
    FrontAxle_Left_y = FrontAxle_Center_y - (d/2)*sin(psi);

    RearAxle_Right_x = RearAxle_Center_x + (d/2)*cos(psi);
    RearAxle_Right_y = RearAxle_Center_y + (d/2)*sin(psi);

    RearAxle_Left_x = RearAxle_Center_x - (d/2)*cos(psi);
    RearAxle_Left_y = RearAxle_Center_y - (d/2)*sin(psi);

    FrontAxle = [FrontAxle_Left_x FrontAxle_Right_x; FrontAxle_Left_y FrontAxle_Right_y];
    RearAxle = [RearAxle_Left_x RearAxle_Right_x; RearAxle_Left_y RearAxle_Right_y];
    
    RightFrontTire_Front_x = FrontAxle_Right_x - rW*sin(psi+delta);
    RightFrontTire_Front_y = FrontAxle_Right_y + rW*cos(psi+delta);

    RightFrontTire_Back_x = FrontAxle_Right_x + rW*sin(psi+delta);
    RightFrontTire_Back_y = FrontAxle_Right_y - rW*cos(psi+delta);

    RightRearTire_Front_x = RearAxle_Right_x - rW*sin(psi);
    RightRearTire_Front_y = RearAxle_Right_y + rW*cos(psi);

    RightRearTire_Back_x = RearAxle_Right_x + rW*sin(psi);
    RightRearTire_Back_y = RearAxle_Right_y - rW*cos(psi);

    LeftFrontTire_Front_x = FrontAxle_Left_x - rW*sin(psi+delta);
    LeftFrontTire_Front_y = FrontAxle_Left_y + rW*cos(psi+delta);

    LeftFrontTire_Back_x = FrontAxle_Left_x + rW*sin(psi+delta);
    LeftFrontTire_Back_y = FrontAxle_Left_y - rW*cos(psi+delta);

    LeftRearTire_Front_x = RearAxle_Left_x - rW*sin(psi);
    LeftRearTire_Front_y = RearAxle_Left_y + rW*cos(psi);

    LeftRearTire_Back_x = RearAxle_Left_x + rW*sin(psi);
    LeftRearTire_Back_y = RearAxle_Left_y - rW*cos(psi);


    RightFrontTire = [RightFrontTire_Front_x RightFrontTire_Back_x; RightFrontTire_Front_y RightFrontTire_Back_y];
    RightRearTire = [RightRearTire_Front_x RightRearTire_Back_x; RightRearTire_Front_y RightRearTire_Back_y];
    LeftFrontTire = [LeftFrontTire_Front_x LeftFrontTire_Back_x; LeftFrontTire_Front_y LeftFrontTire_Back_y];
    LeftRearTire = [LeftRearTire_Front_x LeftRearTire_Back_x; LeftRearTire_Front_y LeftRearTire_Back_y];
    
   
    
    plot(FrontBody(1,:), FrontBody(2,:), 'Color', 'r', 'LineWidth', 2.5)
    hold on;
    plot(RearBody(1,:), RearBody(2,:),'Color', 'r', 'LineWidth', 2.5)
    plot(FrontAxle(1,:), FrontAxle(2,:),'Color','r', 'LineWidth', 2.5);
    plot (RearAxle(1,:), RearAxle (2,:),'Color','r', 'LineWidth', 2.5);
    plot(RightFrontTire(1,:), RightFrontTire(2,:), 'k', 'LineWidth', 3);
    plot(RightRearTire(1,:), RightRearTire(2,:), 'k', 'LineWidth', 3);
    plot(LeftFrontTire(1,:), LeftFrontTire(2,:), 'k', 'LineWidth', 3);
    plot(LeftRearTire(1,:), LeftRearTire(2,:), 'k', 'LineWidth', 3);
    hold off;
end

function [E, N, psi] = convertPathToGlobal( world,s,e, dPsi )
% converts s and e vectors along a path defined by world into EN global coordinates
n = length(s);
E = zeros(n,1);
N = zeros(n,1);

% for i=1:n
%     if( s(i)>world.roadLength && world.closedMap )
%         s(i) = s(i)-world.roadLength; 
%     end
% end

centE = interp1(world.s,world.roadE, s);
centN = interp1(world.s,world.roadN, s);
theta = interp1(world.s,world.roadPsi, s);
psi = theta + dPsi;

for i=1:n
    E(i) = centE(i) - e(i)*sin(pi/2-theta(i));
    N(i) = centN(i) - e(i)*cos(pi/2-theta(i));
end

end