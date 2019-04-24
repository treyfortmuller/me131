%% Author: Tony Zheng
clear
clc
close all

%% Mapping a forward distance (with no lateral movement) to a number of y_newPixels
%xI = 1.5,2ft,2.5ft,3ft,3.5ft,4ft,4.5ft,5ft, yI=0
convertPixelFrame_Topleft_to_BottomCenter = @(xy,i) [xy(:,1,i)-320,480-xy(:,2,i)];
xPixel_yPixel_centerline=[322,424;
    320,358;
    319,324;
    318,303;
    318,288;
    316,278;
    316,270;
    316,263];
xPixel_yPixel_centerline = convertPixelFrame_Topleft_to_BottomCenter(xPixel_yPixel_centerline,1);
xInertial_centerline = [1.5;2;2.5;3;3.5;4;4.5;5];
xInertial_to_yPixel_Matrix = polyfit([1.2;xInertial_centerline],[0;xPixel_yPixel_centerline(:,2)],4);
xInertial_to_yPixel_vals =  polyval(xInertial_to_yPixel_Matrix, 0:.1:5);
plot(xInertial_centerline,xPixel_yPixel_centerline(:,2),[0:.1:5],xInertial_to_yPixel_vals,'--')
xlabel('x_{Inertial} = 1 to 5 ft, y_{Inertial} = 0 ft')
ylabel('y_{newPixel}')
title('x_{Inertial} vs y_{newPixel} with a fixed 0 lateral distance')
ylim([0 300])

%% Flipped axis to get the equation in reverse
figure
yPixel_to_xInertial_Matrix = polyfit([0;xPixel_yPixel_centerline(:,2)],[1.2;xInertial_centerline],4);
yPixel_to_xInertial_vals = polyval(yPixel_to_xInertial_Matrix,[0:220]);
plot(xPixel_yPixel_centerline(:,2),xInertial_centerline,[0:220],yPixel_to_xInertial_vals,'--')
ylabel('x_{Inertial} = 1 to 5 ft, y_{Inertial} = 0 ft')
xlabel('y_{newPixel}')
legend('4th order polynomial','Location','Best')
title('FLIPPED:y_{newPixel} vs x_{Inertial} with a fixed 0 lateral distance')

%% Plotting the objects at varying y_Inertial for different x_Inertial 
% xi = 2, yi by 0.25ft
% xPixel_yPixel_lateral
% (:,:,1) - xInertial = 2 ft, yInertial = 0, 0.25, 0.5, 0.75, 1 ft
xInertial_lateral = [2;3;4;5];
xPixel_yPixel_lateral(:,:,1) = [320,358;
                                386,355
                                452,355;
                                522,354;
                                597,355;];
xPixel_yPixel_lateral(:,:,2) = [318,303;
                                399,301;
                                440,300;
                                481,299;
                                569,297;];
xPixel_yPixel_lateral(:,:,3) = [316,278;
                                374,273;
                                432,272;
                                491,271;
                                555,271;];
xPixel_yPixel_lateral(:,:,4) = [316,263;
                                360,259;
                                406,259;
                                452,259;
                                495,257];
yInertial_lateral(:,:,1) = [0;0.25;0.5;0.75;1];
yInertial_lateral(:,:,2) = [0;0.5;0.75;1;1.5];
yInertial_lateral(:,:,3) = [0;0.5;1;1.5;2];
yInertial_lateral(:,:,4) = [0;0.5;1;1.5;2];
figure
hold all
for i = 1:size(xPixel_yPixel_lateral,3)
    xPixel_yPixel_lateral(:,:,i) = convertPixelFrame_Topleft_to_BottomCenter(xPixel_yPixel_lateral,i);
    plot(xPixel_yPixel_lateral(:,1,i),xPixel_yPixel_lateral(:,2,i))
end
xlabel('x_{newPixel}')
ylabel('y_{newPixel}')  
title('Pixels only: x_{newPixel} vs y_{newPixel}')

%% Changing the previous plot to have the given y_Inertial rather than x_newPixel for the x axis
figure
hold all
for i = 1:size(xPixel_yPixel_lateral,3)
    plot(yInertial_lateral(:,1,i),xPixel_yPixel_lateral(:,2,i))
end
xlabel('-y_{Inertial}')
ylabel('y_{newPixel}')  
title('Lateral motion: y_{Inertial} vs y_{newPixel}')

%% Offset each set of measurements at different x_Inertials so that the y_newPixel starts at 0 rather than the given y_newPixel (subtract each row by the first value)
yPixel_start_zero = @(xy) [xy(:,2)-xy(1,2)];
figure
hold all
for i = 1:size(xPixel_yPixel_lateral,3)
    yPixel_lateral_zero(:,:,i) = yPixel_start_zero(xPixel_yPixel_lateral(:,:,i));
    plot(yInertial_lateral(:,1,i),yPixel_lateral_zero(:,:,i))
end
xlabel('-y_{Inertial}')
ylabel('y_{newPixel}') 
%legend('x_I = 2ft','x_I = 3ft','x_I = 4ft','x_I = 5ft')
title('Lateral motion (pixel start at 0): y_{Inertial} vs y_{newPixel}')

%% Find a polynomial fit for all those data points
yInertial_vs_yPixel_polyfit=@(yi,yp) polyfit(yi,yp,3);
yInertial_lateral_polyvals_combined = [];
yInertial_lateral_linspaces_combined = [];
for i = 1:size(xPixel_yPixel_lateral,3)
    slope_yInertial_vs_yPixelzero(:,:,i) = yInertial_vs_yPixel_polyfit(yInertial_lateral(:,1,i),yPixel_lateral_zero(:,:,i));
    yInertial_lateral_polyvals(:,:,i) = polyval(slope_yInertial_vs_yPixelzero(:,:,i),linspace(0,yInertial_lateral(end,1,i),50));
    yInertial_lateral_polyvals_combined = [yInertial_lateral_polyvals_combined;yInertial_lateral_polyvals(:,:,i)'];
    yInertial_lateral_linspaces_combined = [yInertial_lateral_linspaces_combined;linspace(0,yInertial_lateral(end,1,i),50)'];
end

f1Matrix = yInertial_vs_yPixel_polyfit(yInertial_lateral_linspaces_combined,yInertial_lateral_polyvals_combined);
f1_polyvals = polyval(f1Matrix,yInertial_lateral_linspaces_combined);
hold on
plot(yInertial_lateral_linspaces_combined,f1_polyvals,'*')
legend('x_I = 2ft','x_I = 3ft','x_I = 4ft','x_I = 5ft','3rd order poly','Location','best')

%% Plot the varying lateral distance y_Inertial vs. x_newPixel

figure
hold all
for i = 1:size(xPixel_yPixel_lateral,3)
    plot(yInertial_lateral(:,:,i),xPixel_yPixel_lateral(:,1,i))
end
xlabel('-y_{Inertial}')
ylabel('x_{newPixel}')  

%% Calculate the slope of the line for each x_Inertial
 m=@(yi,xn) polyfit(yi,xn,1);
 
 for i = 1:size(xPixel_yPixel_lateral,3)
 	slope_yInertial_vs_xPixelzero(:,:,i) = m(yInertial_lateral(:,:,i),xPixel_yPixel_lateral(:,1,i));
	yInertial_lateral_polyvals(:,:,i) = polyval(slope_yInertial_vs_xPixelzero(:,:,i),linspace(0,yInertial_lateral(end,1,i),50));
 end
 
%% Taking a polyfit of each slope vs x_inertial
for i = 1:size(xPixel_yPixel_lateral,3)
    mlist(i,1) = slope_yInertial_vs_xPixelzero(:,1,i);
    blist(i,1) = slope_yInertial_vs_xPixelzero(:,2,i);
end

f2Matrix = polyfit(xInertial_lateral,mlist,3);
mvals = polyval(f2Matrix,xInertial_lateral);

%% Taking a polyfit of each offset vs x_inertial

bMatrix = polyfit(xInertial_lateral,blist,3);
bvals = polyval(bMatrix,xInertial_lateral);

%plot(mlist(:,1),mlist(:,2),mlist(:,1),mvals)
% 3rd order fit between the xI and m

%% Example of an arbitrary x_inertial to see if it lines up with my expectations
yis = 0:.2:2;
xnpis = polyval(f2Matrix,2.5)*yis+polyval(bMatrix,2.5);
hold on
plot(yis,xnpis)

%% Plotting the given x_inertials with my slope equation
hold on
for i = 1:size(xPixel_yPixel_lateral,3)
    plot(linspace(0,yInertial_lateral(end,1,i),50),yInertial_lateral_polyvals(:,:,i),'--')
end
title('Lateral motion: y_{Inertial} vs x_{newPixel} at varying forward distance')
legend('x_I = 2ft','x_I = 3ft','x_I = 4ft','x_I = 5ft','Test: x_I = 2.5ft','Location','best')

%% Plot slope vs x_inertial
figure
plot(xInertial_lateral,mlist)
title('Slope vs. x_{Inertial}')
xlabel('x_{Inertial}')
ylabel('Slope (x_{newPixel}/y_{Inertial})')

%% Plot offset B vs x_inertial
figure
plot(xInertial_lateral,blist)
title('Offset b vs. x_{Inertial}')
xlabel('x_{Inertial}')
ylabel('b (x_{newPixel}/y_{Inertial})')

%% Plotting the original points (Given x_inertial and y_inertial, when I run them through my equations, do they match the measured pixel positions?)

calc_ynp_to_xI = @(ynp) polyval(yPixel_to_xInertial_Matrix,ynp);
calc_xnp_to_yI = @(xI,xnp) (xnp-polyval(bMatrix,xI))./polyval(f2Matrix,xI);

figure
hold all
for i = 1:size(xPixel_yPixel_lateral,3)
    xI_calculated(:,:,i) = calc_ynp_to_xI(xPixel_yPixel_lateral(:,2,i));
    yI_calculated(:,:,i) = calc_xnp_to_yI(xI_calculated(:,:,i),xPixel_yPixel_lateral(:,1,i));
    xI_true(:,:,i) = xInertial_lateral(i)*ones(length(xPixel_yPixel_lateral(:,1,i)),1);
    plot(yInertial_lateral(:,:,i),xI_true(:,:,i),'o',yI_calculated(:,:,i),xI_calculated(:,:,i),'x')
end

ylim([0 6])
ylabel('x_{Inertial}')
xlabel('-y_{Inertial}')
title('Skewed')

%% Skew Correction
calc_yI_yp_skew = @(yI) polyval(f1Matrix,yI);

figure
hold all
for i = 1:size(xPixel_yPixel_lateral,3)
    yPixel_corrected(:,:,i) = calc_yI_yp_skew(yI_calculated(:,:,i));
    xInertial_corrected(:,:,i) = calc_ynp_to_xI(xPixel_yPixel_lateral(:,2,i)-yPixel_corrected(:,:,i));
    yInertial_corrected(:,:,i) = calc_xnp_to_yI(xInertial_corrected(:,:,i),xPixel_yPixel_lateral(:,1,i));
    plot(yInertial_lateral(:,:,i),xI_true(:,:,i),'o',yInertial_corrected(:,:,i),xInertial_corrected(:,:,i),'x')
end
ylim([0 6])
ylabel('x_{Inertial}')
xlabel('-y_{Inertial}')
title('Corrected')

%% Clear Workspace
save('Calibration_Matrices.mat','f1Matrix','f2Matrix','bMatrix','xInertial_to_yPixel_Matrix','yPixel_to_xInertial_Matrix')
clear
load Calibration_Matrices

