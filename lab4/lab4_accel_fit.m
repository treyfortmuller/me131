% performs the least squares regression on test data to determine a
% transfer function for commanded PWM -> velocity

%% Load Data
% bring in the matlab data timeseries for a working encoder and the PWM
load('ID_rosbags/matFiles/speedID_1.mat');
PWM_ts1 = sig{10}; % motor PWM time series
encoder_FL1 = sig{12};

load('ID_rosbags/matFiles/speedID_2.mat');
PWM_ts2 = sig{10}; % motor PWM time series
encoder_FL2 = sig{12};

load('ID_rosbags/matFiles/speedID_3.mat');
PWM_ts3 = sig{10}; % motor PWM time series
encoder_FL3 = sig{12};

load('ID_rosbags/matFiles/speedID_4.mat');
PWM_ts4 = sig{10}; % motor PWM time series
encoder_FL4 = sig{12};

load('ID_rosbags/matFiles/speedID_5.mat');
PWM_ts5 = sig{10}; % motor PWM time series
encoder_FL5 = sig{12};

load('ID_rosbags/matFiles/speedID_6.mat');
PWM_ts6 = sig{10}; % motor PWM time series
encoder_FL6 = sig{12};

load('ID_rosbags/matFiles/speedID_7.mat');
PWM_ts7 = sig{10}; % motor PWM time series
encoder_FL7 = sig{12};

% plot the PWM vs time for a deliverable plot
% figure()
% plot(PWM_ts1)

% extract the data from the time series object
enc1_data = encoder_FL1.Data;
enc2_data = encoder_FL2.Data;
enc3_data = encoder_FL3.Data;
enc4_data = encoder_FL4.Data;
enc5_data = encoder_FL5.Data;
enc6_data = encoder_FL6.Data;
enc7_data = encoder_FL7.Data;

%% Resample PWM for Synchronized Time
% determine whether the encoder or PWM commands are higher rate
size(PWM_ts1.Data); % 398
size(encoder_FL1.Data); % 204

% downsampling the PWM to the encoder (to avoid issues with upsampling the 
% encoder data), we'll rectify the encoder data later.

% resampling the encoder timeseries to match the time for the PWM commands
resampled_PWM1 = resample(PWM_ts1, encoder_FL1.Time);
resampled_PWM2 = resample(PWM_ts2, encoder_FL2.Time);
resampled_PWM3 = resample(PWM_ts3, encoder_FL3.Time);
resampled_PWM4 = resample(PWM_ts4, encoder_FL4.Time);
resampled_PWM5 = resample(PWM_ts5, encoder_FL5.Time);
resampled_PWM6 = resample(PWM_ts6, encoder_FL6.Time);
resampled_PWM7 = resample(PWM_ts7, encoder_FL7.Time);

% we won't resample the encoder data
% resampled_enc1 = resample(encoder_FL1, PWM_ts1.Time);
% resampled_enc2 = resample(encoder_FL2, PWM_ts2.Time);
% resampled_enc3 = resample(encoder_FL3, PWM_ts3.Time);
% resampled_enc4 = resample(encoder_FL4, PWM_ts4.Time);
% resampled_enc5 = resample(encoder_FL5, PWM_ts5.Time);
% resampled_enc6 = resample(encoder_FL6, PWM_ts6.Time);
% resampled_enc7 = resample(encoder_FL7, PWM_ts7.Time);

% extract the data from the time series object, uncomment for resampling
% encoder data
% enc1_data = resampled_enc1.Data;
% enc2_data = resampled_enc2.Data;
% enc3_data = resampled_enc3.Data;
% enc4_data = resampled_enc4.Data;
% enc5_data = resampled_enc5.Data;
% enc6_data = resampled_enc6.Data;
% enc7_data = resampled_enc7.Data;

% plot resampled PWM for debug
% figure()
% legend()
% plot(resampled_PWM1)
% plot(resampled_PWM2)
% plot(resampled_PWM3)
% plot(resampled_PWM4)
% plot(resampled_PWM5)
% plot(resampled_PWM6)
% plot(resampled_PWM7)

% plot encoder data against the index for debug
figure()
legend()
hold on
plot(enc1_data)
plot(enc2_data)
plot(enc3_data)
plot(enc4_data)
plot(enc5_data)
plot(enc6_data)
plot(enc7_data)

%% Longitudinal Velocities from Encoders
WHEEL_RAD = 0.1 / 2.0; % wheel radius in meters

% encoder counts converted to wheel radians
RAD_PER_ENC = pi/4; % each encoder count is 1/8th of a revolution

% angular displacement of wheel in radians
ang_dis1 = enc1_data.*RAD_PER_ENC;
ang_dis2 = enc2_data.*RAD_PER_ENC;
ang_dis3 = enc3_data.*RAD_PER_ENC;
ang_dis4 = enc4_data.*RAD_PER_ENC;
ang_dis5 = enc5_data.*RAD_PER_ENC;
ang_dis6 = enc6_data.*RAD_PER_ENC;
ang_dis7 = enc7_data.*RAD_PER_ENC;

% assuming each file has the same rate of data capture for encoders:
% the actual time of the experiment in seconds
interval = (encoder_FL1.TimeInfo.End - encoder_FL1.TimeInfo.Start)*10^-9;

% frequency of encoder data
freq = length(enc1_data)/interval; % clocks per second
time_step = 1/freq; % time steps for encoder data, in seconds

% numerically differentiate the angular displacement
ang_diff = diff(ang_dis1);
ang_vel1 = ang_diff./time_step; % wheel angular vel. in rad/s

ang_diff = diff(ang_dis2);
ang_vel2 = ang_diff./time_step; % wheel angular vel. in rad/s

ang_diff = diff(ang_dis3);
ang_vel3 = ang_diff./time_step; % wheel angular vel. in rad/s

ang_diff = diff(ang_dis4);
ang_vel4 = ang_diff./time_step; % wheel angular vel. in rad/s

ang_diff = diff(ang_dis5);
ang_vel5 = ang_diff./time_step; % wheel angular vel. in rad/s

ang_diff = diff(ang_dis6);
ang_vel6 = ang_diff./time_step; % wheel angular vel. in rad/s

ang_diff = diff(ang_dis7);
ang_vel7 = ang_diff./time_step; % wheel angular vel. in rad/s

% smooth each of the angular velocities
s_ang_vel1 = smoothdata(ang_vel1);
s_ang_vel2 = smoothdata(ang_vel2);
s_ang_vel3 = smoothdata(ang_vel3);
s_ang_vel4 = smoothdata(ang_vel4);
s_ang_vel5 = smoothdata(ang_vel5);
s_ang_vel6 = smoothdata(ang_vel6);
s_ang_vel7 = smoothdata(ang_vel7);

% the longitudinal velocity 
long_vel1 = WHEEL_RAD*s_ang_vel1;
long_vel2 = WHEEL_RAD*s_ang_vel2;
long_vel3 = WHEEL_RAD*s_ang_vel3;
long_vel4 = WHEEL_RAD*s_ang_vel4;
long_vel5 = WHEEL_RAD*s_ang_vel5;
long_vel6 = WHEEL_RAD*s_ang_vel6;
long_vel7 = WHEEL_RAD*s_ang_vel7;

% plot longitudinal velocity against the index for debug
figure()
legend()
hold on
plot(long_vel1)
plot(long_vel2)
plot(long_vel3)
plot(long_vel4)
plot(long_vel5)
plot(long_vel6)
plot(long_vel7)

%% Numerically differentiate the longitudinal velocity for long accel
vel_diff = diff(long_vel1);
long_accel1 = vel_diff./time_step;

vel_diff = diff(long_vel2);
long_accel2 = vel_diff./time_step;

vel_diff = diff(long_vel3);
long_accel3 = vel_diff./time_step;

vel_diff = diff(long_vel4);
long_accel4 = vel_diff./time_step;

vel_diff = diff(long_vel5);
long_accel5 = vel_diff./time_step;

vel_diff = diff(long_vel6);
long_accel6 = vel_diff./time_step;

vel_diff = diff(long_vel7);
long_accel7 = vel_diff./time_step;

% smooth the data after numerically differentiating
s_ang_accel1 = smoothdata(long_accel1);
s_ang_accel2 = smoothdata(long_accel2);
s_ang_accel3 = smoothdata(long_accel3);
s_ang_accel4 = smoothdata(long_accel4);
s_ang_accel5 = smoothdata(long_accel5);
s_ang_accel6 = smoothdata(long_accel6);
s_ang_accel7 = smoothdata(long_accel7);

% plot longitudinal acceleration against the index for debug
figure()
legend()
hold on
plot(s_ang_accel1)
% plot(s_ang_accel2)
% plot(s_ang_accel3)
plot(s_ang_accel4)
plot(s_ang_accel5)
% plot(s_ang_accel6)
plot(s_ang_accel7)

% data 2, 3 and 6 are noisier than the rest, we'll exclude them from the
% linear regression

%% Clean the PWM data from NaNs and slice the other data to size match
% compare sizes, we used a forward Euler difference to estimate the
% derivates so we tructate the final values to correct the sizes
rec_pwm1 = resampled_PWM1.Data;
rec_pwm4 = resampled_PWM4.Data;
rec_pwm5 = resampled_PWM5.Data;
rec_pwm7 = resampled_PWM7.Data;

% rectify the data by excluding any NaNs
% trial 1 data
nan_indicies = find(isnan(rec_pwm1));
rec_pwm1 = rec_pwm1(1:nan_indicies(1) - 1); % remove all the NaNs
s_ang_accel1 = s_ang_accel1(1:length(rec_pwm1));
rec_long_vel1 = rec_long_vel1(1:length(rec_pwm1));

% trial 4 data
nan_indicies = find(isnan(rec_pwm4));
rec_pwm4 = rec_pwm4(1:nan_indicies(1) - 1); % remove all the NaNs
s_ang_accel4 = s_ang_accel4(1:length(rec_pwm4));
rec_long_vel4 = rec_long_vel4(1:length(rec_pwm4));

% trial 5 data
nan_indicies = find(isnan(rec_pwm5));
rec_pwm5 = rec_pwm5(1:nan_indicies(1) - 1); % remove all the NaNs
s_ang_accel5 = s_ang_accel5(1:length(rec_pwm5));
rec_long_vel5 = rec_long_vel5(1:length(rec_pwm5));

% trial 7 data
nan_indicies = find(isnan(rec_pwm7));
rec_pwm7 = rec_pwm7(1:nan_indicies(1) - 1); % remove all the NaNs
s_ang_accel7 = s_ang_accel7(1:length(rec_pwm7));
rec_long_vel7 = rec_long_vel7(1:length(rec_pwm7));

%% Construct the Matrices for Linear Regression
% construct the vdot matrix by vertically concatinating the smoothed
% ang_accels

vdot = [s_ang_accel1; s_ang_accel4; s_ang_accel5; s_ang_accel7];
size(vdot);

v1 = [rec_long_vel1, rec_pwm1];
v4 = [rec_long_vel4, rec_pwm4];
v5 = [rec_long_vel5, rec_pwm5];
v7 = [rec_long_vel7, rec_pwm7];

v = [v1; v4; v5; v7];
size(v);

%% Perform the Linear Regression
w = v\vdot % perform least squares to obtain coefficients for a TF

% result of the linear regression:
% a = -0.0943
% b = 0.0001

%% Compare Transfer Function prediction with 5 Recorded Values

% plot longitudinal velocity against the index for debug
figure()
legend()
hold on
plot(long_vel1)
plot(long_vel4)
plot(long_vel5)
plot(long_vel7)
