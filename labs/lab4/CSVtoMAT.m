clear
close all
clc
mkdir matFolder
experiment_list = dir('*.csv');
num_tests=length(experiment_list);
for experiment = 1 : num_tests
    thisfile = experiment_list(experiment).name;
	sig = cell(1,15);
    [~, ~, raw] = xlsread(thisfile);
    p = strcmpi('New topic',raw(:,1));
    rowNum = find(p==1);
    for i = 1:length(rowNum)
        if i<length(rowNum)
            iNext = rowNum(i+1)-1;
        else
            iNext = size(raw,1);
        end
        topicName = raw{rowNum(i),2};
        if isequal(topicName,'/ecu_pwm')
            sig{10} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,2)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','motor_pwm');
            sig{11} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,3)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','servo_pwm');
        elseif isequal(topicName,'/imu/data')
            sig{1} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,9)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','roll');
            sig{2} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,10)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','pitch');
            sig{3} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,11)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','yaw');
            sig{4} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,15)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','angular_velocity_x');
            sig{5} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,16)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','angular_velocity_y');
            sig{6} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,17)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','angular_velocity_z');
            sig{7} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,20)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','linear_acceleration_x');
            sig{8} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,21)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','linear_acceleration_y');
            sig{9} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,22)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','linear_acceleration_z');
        elseif isequal(topicName,'/encoder')
            sig{12} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,2)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','encoder_FL');
            sig{13} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,3)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','encoder_FR');
            sig{14} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,4)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','encoder_BL');
            sig{15} = timeseries(cell2mat(raw(rowNum(i)+2:iNext,5)),cell2mat(raw(rowNum(i)+2:iNext,1)),'Name','encoder_BR');
        end
    end
    save(['matFolder/',thisfile(1:end-4)],'sig')
    disp([num2str(experiment),' - ',thisfile(1:end-4),'.mat generated'])
end
