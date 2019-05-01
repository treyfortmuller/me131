%% Author: Tony Zheng
clear
clc
close all

%% Load pixel coordinates
data = xlsread('PixelCoordinatesSheet');

[A,B] = find(~isnan(data));
D = unique(A);
E = unique(B);
for i = 1:length(D)/2
    temp = data(D(i*2-1:i*2),E);
    [a,b] = find(~isnan(temp));
    c = unique(a);
    d = unique(b);
    xPixel_yPixel_lateral{i} = temp(min(c):max(c),min(d):max(d))';
end

%% Mapping a forward distance (with no lateral movement) to a number of y_newPixels
convertPixelFrame_Topleft_to_BottomCenter = @(xy) [xy(:,1)-320,480-xy(:,2)];
for i = 1:size(xPixel_yPixel_lateral,2)
    xPixel_yPixel_centerline(i,:) = xPixel_yPixel_lateral{i}(round(size(xPixel_yPixel_lateral{i},1)/2),:);
end
xPixel_yPixel_centerline = convertPixelFrame_Topleft_to_BottomCenter(xPixel_yPixel_centerline);

% TODO: CHANGE THESE
centerline_max = 0.7525; % the farthest center dot distance in meters in the in the inertial frame
centerline_min = 0.3524; % the closest center dot distance in meters in the inertial frame

centerline_interval = -0.1;
xInertial_centerline = [centerline_max:centerline_interval:centerline_min]';
xInertial_to_yPixel_Matrix = polyfit(xInertial_centerline,xPixel_yPixel_centerline(:,2),3);
xInertial_to_yPixel_vals =  polyval(xInertial_to_yPixel_Matrix, 0.4:.1:1.1);
plot(xInertial_centerline,xPixel_yPixel_centerline(:,2),[0.4:.1:1.1],xInertial_to_yPixel_vals,'--')
xlabel('x_{Inertial} (m) at y_{Inertial} = 0 m')
ylabel('y_{newPixel}')
title('x_{Inertial} vs y_{newPixel} with a fixed 0 lateral distance')


%% Flipped axis to get the equation in reverse
figure
yPixel_to_xInertial_Matrix = polyfit([xPixel_yPixel_centerline(:,2)],[xInertial_centerline],3);
yPixel_to_xInertial_vals = polyval(yPixel_to_xInertial_Matrix,[0:220]);
plot(xPixel_yPixel_centerline(:,2),xInertial_centerline,[0:220],yPixel_to_xInertial_vals,'--')
ylabel('x_{Inertial} (m) at y_{Inertial} = 0 m')
xlabel('y_{newPixel}')
legend('3rd order polynomial','Location','Best')
title('FLIPPED:y_{newPixel} vs x_{Inertial} with a fixed 0 lateral distance')

%% Plotting the objects at varying y_Inertial for different x_Inertial 
yInertial_lateral{1} = [-0.3:0.1:0.3]';
yInertial_lateral{2} = [-0.3:0.1:0.3]';
yInertial_lateral{3} = [-0.3:0.1:0.3]';
yInertial_lateral{4} = [-0.2:0.1:0.2]';
yInertial_lateral{5} = [-0.1:0.1:0.1]';

xInertial_lateral = [centerline_max:-.1:centerline_max+(size(xPixel_yPixel_lateral,2)-1)*-0.1]';

figure
hold all
for i = 1:size(xPixel_yPixel_lateral,2)
    xPixel_yPixel_lateral{i} = convertPixelFrame_Topleft_to_BottomCenter(xPixel_yPixel_lateral{i});
    plot(xPixel_yPixel_lateral{i}(:,1),xPixel_yPixel_lateral{i}(:,2))
end
xlabel('x_{newPixel}')
ylabel('y_{newPixel}')  
title('Pixels only: x_{newPixel} vs y_{newPixel}')

%% Changing the previous plot to have the given y_Inertial rather than x_newPixel for the x axis
figure
hold all
for i = 1:size(xPixel_yPixel_lateral,2)
    plot(yInertial_lateral{i}(:,1),xPixel_yPixel_lateral{i}(:,2))
end
xlabel('-y_{Inertial}')
ylabel('y_{newPixel}')  
title('Lateral motion: y_{Inertial} vs y_{newPixel}')

%% Offset each set of measurements at different x_Inertials so that the y_newPixel starts at 0 rather than the given y_newPixel (subtract each row by the first value)
yPixel_start_zero = @(xy) [xy(:,2)-xy(round(size(xy,1)/2),2)];
figure
hold all
for i = 1:size(xPixel_yPixel_lateral,2)
    yPixel_lateral_zero{i} = yPixel_start_zero(xPixel_yPixel_lateral{i});
    plot(yInertial_lateral{i}(:,1),yPixel_lateral_zero{i})
end
xlabel('-y_{Inertial}')
ylabel('y_{newPixel}') 
title('Lateral motion (pixel start at 0): y_{Inertial} vs y_{newPixel}')

%% Find a polynomial fit for all those data points
yInertial_vs_yPixel_polyfit=@(yi,yp) polyfit(yi,yp,3);
yInertial_lateral_polyvals_combined = [];
yInertial_lateral_linspaces_combined = [];
for i = 1:size(xPixel_yPixel_lateral,2)
    slope_yInertial_vs_yPixelzero{i} = yInertial_vs_yPixel_polyfit(yInertial_lateral{i}(:,1),yPixel_lateral_zero{i});
    yInertial_lateral_polyvals{i} = polyval(slope_yInertial_vs_yPixelzero{i},linspace(yInertial_lateral{i}(1,1),yInertial_lateral{i}(end,1),50));
    yInertial_lateral_polyvals_combined = [yInertial_lateral_polyvals_combined;yInertial_lateral_polyvals{i}'];
    yInertial_lateral_linspaces_combined = [yInertial_lateral_linspaces_combined;linspace(yInertial_lateral{i}(1,1),yInertial_lateral{i}(end,1),50)'];
end

f1Matrix = yInertial_vs_yPixel_polyfit(yInertial_lateral_linspaces_combined,yInertial_lateral_polyvals_combined);
f1_polyvals = polyval(f1Matrix,yInertial_lateral_linspaces_combined);
hold on
plot(yInertial_lateral_linspaces_combined,f1_polyvals,'*')
legend('x_I = 0.56 m','x_I = 0.66 m','x_I = 0.76 m','x_I = 0.86 m','x_I = 0.96 m','3rd order poly','Location','best')

%% Plot the varying lateral distance y_Inertial vs. x_newPixel

figure
hold all
for i = 1:size(xPixel_yPixel_lateral,2)
    plot(yInertial_lateral{i},xPixel_yPixel_lateral{i}(:,1))
end
xlabel('-y_{Inertial}')
ylabel('x_{newPixel}')  

%% Calculate the slope of the line for each x_Inertial
 m=@(yi,xn) polyfit(yi,xn,1);
 
 for i = 1:size(xPixel_yPixel_lateral,2)
 	slope_yInertial_vs_xPixelzero{i} = m(yInertial_lateral{i},xPixel_yPixel_lateral{i}(:,1));
	yInertial_lateral_polyvals{i} = polyval(slope_yInertial_vs_xPixelzero{i},linspace(yInertial_lateral{i}(1,1),yInertial_lateral{i}(end,1),50));
 end
 
%% Taking a polyfit of each slope vs x_inertial
for i = 1:size(xPixel_yPixel_lateral,2)
    mlist(i,1) = slope_yInertial_vs_xPixelzero{i}(:,1);
    blist(i,1) = slope_yInertial_vs_xPixelzero{i}(:,2);
end

f2Matrix = polyfit(xInertial_lateral,mlist,3);
mvals = polyval(f2Matrix,xInertial_lateral);

%% Taking a polyfit of each offset vs x_inertial

bMatrix = polyfit(xInertial_lateral,blist,3);
bvals = polyval(bMatrix,xInertial_lateral);

%% Example of an arbitrary x_inertial to see if it lines up with my expectations
yis = -.3:0.05:.3;
xnpis = polyval(f2Matrix,0.7)*yis+polyval(bMatrix,0.7);
hold on
plot(yis,xnpis)

%% Plotting the given x_inertials with my slope equation
hold on
for i = 1:size(xPixel_yPixel_lateral,2)
    plot(linspace(yInertial_lateral{i}(1,1),yInertial_lateral{i}(end,1),50),yInertial_lateral_polyvals{i},'--')
end
title('Lateral motion: y_{Inertial} vs x_{newPixel} at varying forward distance')
legend('x_I = 0.56 m','x_I = 0.66 m','x_I = 0.76 m','x_I = 0.86 m','x_I = 0.96 m','Test: x_I = 0.7 m','Location','best')

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
for i = 1:size(xPixel_yPixel_lateral,2)
    xI_calculated{i} = calc_ynp_to_xI(xPixel_yPixel_lateral{i}(:,2));
    yI_calculated{i} = calc_xnp_to_yI(xI_calculated{i},xPixel_yPixel_lateral{i}(:,1));
    xI_true{i} = xInertial_lateral(i)*ones(length(xPixel_yPixel_lateral{i}(:,1)),1);
    plot(yInertial_lateral{i},xI_true{i},'o',yI_calculated{i},xI_calculated{i},'x')
end

ylabel('x_{Inertial}')
xlim([-0.4 0.4])
xlabel('-y_{Inertial}')
title('Skewed')

%% Skew Correction
calc_yI_yp_skew = @(yI) polyval(f1Matrix,yI);

figure
hold all
for i = 1:size(xPixel_yPixel_lateral,2)
    yPixel_corrected{i} = calc_yI_yp_skew(yI_calculated{i});
    xInertial_corrected{i} = calc_ynp_to_xI(xPixel_yPixel_lateral{i}(:,2)-yPixel_corrected{i});
    yInertial_corrected{i} = calc_xnp_to_yI(xInertial_corrected{i},xPixel_yPixel_lateral{i}(:,1));
    plot(yInertial_lateral{i},xI_true{i},'o',yInertial_corrected{i},xInertial_corrected{i},'x')
end

ylabel('x_{Inertial}')
xlabel('-y_{Inertial}')
xlim([-0.4 0.4])
title('Corrected')

%% Clear Workspace
save('Calibration_Matrices.mat','f1Matrix','f2Matrix','bMatrix','xInertial_to_yPixel_Matrix','yPixel_to_xInertial_Matrix')
clear
load Calibration_Matrices

