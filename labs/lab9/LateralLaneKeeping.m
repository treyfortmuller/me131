%% 3D Vehicle Simulator
% ===============================
% AUTHOR: Francesco Borrelli, Yuri Murakami Glauthier
% UPDATED 4/15/2019
clc
clear
close all

%% Example Images with location data
% location data for one time step. Use this code to get sample location
% data. To change the image of location data change colordata variable 
% change ImageChoice.
ImageChoice = 2; % Chose from 1, 2, and 3.

load('SampleImage1.mat')
load('SampleImage2.mat')
load('SampleImage3.mat')

figure()
subplot(1,3,1)
imshow(SampleImage1)
subplot(1,3,2)
imshow(SampleImage2)
subplot(1,3,3)
imshow(SampleImage3)

rdesired = 206;
gdesired = 206;
bdesired = 41;

switch ImageChoice
    case 1
        colordata = SampleImage1;
    case 2
        colordata = SampleImage2;
    case 3
        colordata = SampleImage3;
end

for i = 1:400
    for j = 1:640
        if colordata(i,j,1) == rdesired &&...
                colordata(i,j,2) == gdesired &&...
                colordata(i,j,3) == bdesired
            colordata(i,j,1) = 255;
        else
            colordata(i,j,1) = 0;
            colordata(i,j,2) = 0;
            colordata(i,j,3) = 0;
        end
    end
end

figure()
imshow(colordata)

lanes = colordata;

pixelsize = 8/640; %m/pixel
locations = [0,0;0,0];
[Ylocation,Xlocation] = find(lanes ~= 0);
coder.varsize('Xlocation',[256000 2]);
coder.varsize('Ylocation',[256000 2]);
coder.varsize('locations',[256000 2]);
Xlocation = 5-Xlocation.*pixelsize;
Ylocation = Ylocation.*pixelsize-4;

locations = [Xlocation,Ylocation]; %same output as location function

%% Initial Conditions

close all

initial_x = 0;
initial_y = 0;
initial_theta = 0;

%% Controller Gains
%if you need controller gains to be initialized place them here.

%% Run Sim
sim('LateralSim.slx')