from __future__ import print_function, division

import sys
import numpy as np
import matplotlib.pyplot as plt
from convertToPickle import get_data

dat, fname = get_data(sys.argv)
if len(sys.argv) < 3:
    raise AssertionError('Failed to specify vehicle ID')
vehID = str(sys.argv[2])
print('Plotting')

figPos = plt.figure() 
figPos.suptitle(fname)
n = 2  # num sub-plots
figPos.add_subplot(2, 3, 1)
for i in range(2):
    for j in range(3):
        if i==j and i==0:
            figPos.add_subplot(2, 3, 1+i*3+j)    
        else:
            figPos.add_subplot(2, 3, 1+i*3+j, sharex=figPos.axes[0])    

#plot position
for j in range(3):
    axNo = 0*3+j

    figPos.axes[axNo].plot(dat['/estimator'+vehID]['t'], dat['/estimator'+vehID]['pos'+'xyz'[j]], color='b', label='est')
    figPos.axes[axNo].plot(dat['/mocap_output'+vehID]['t'], dat['/mocap_output'+vehID]['pos'+'xyz'[j]], color='r', label='mocap')
    figPos.axes[axNo].set_ylabel('Pos_'+'xyz'[j])
#plot velocity
for j in range(3):
    axNo = 1*3+j
    figPos.axes[axNo].plot(dat['/estimator'+vehID]['t'], dat['/estimator'+vehID]['vel'+'xyz'[j]], color='b', label='est')
    figPos.axes[axNo].set_ylabel('Vel_'+'xyz'[j])


figPos.axes[0].legend()

if False:
    figAtt = plt.figure()
    figAtt.suptitle(fname)
    n = 2  # num sub-plots
    figAtt.add_subplot(2, 3, 1)
    for i in range(2):
        for j in range(3):
            if i==j and i==0:
                figAtt.add_subplot(2, 3, 1+i*3+j)    
            else:
                figAtt.add_subplot(2, 3, 1+i*3+j, sharex=figAtt.axes[0])    

    #plot angle
    for j in range(3):
        axNo = 0*3+j
        angle = ['yaw','pitch','roll'][j]
        #figAtt.axes[axNo].plot(*removeInvalids(time, df['estimator__att'+angle].values),color='b', label='est')
        #figAtt.axes[axNo].plot(*removeInvalids(time, df['mocap_output__att'+angle].values),color='r', label='mocap')
        #figAtt.axes[axNo].set_ylabel(angle)
    #plot ang velocity
    for j in range(3):
        axNo = 1*3+j
        #figAtt.axes[axNo].plot(*removeInvalids(time, df['estimator__angvel'+'xyz'[j]].values),color='b', label='est')
        #figAtt.axes[axNo].plot(*removeInvalids(time, df['telemetry__rateGyro'+'012'[j]].values),color='g', label='gyro')
        #figAtt.axes[axNo].plot(*removeInvalids(time, df['radio_command__debugvals'+'123'[j]].values),color='r', label='cmd')
        figAtt.axes[axNo].set_ylabel('AngVel_'+'xyz'[j])

    figAtt.axes[0].legend()
    figAtt.axes[3].legend()

plt.show()

