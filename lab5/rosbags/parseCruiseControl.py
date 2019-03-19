from __future__ import print_function, division

import sys
import numpy as np
import matplotlib.pyplot as plt
from convertToPickle import get_data
from operator import add # for element-wise sum of lists
from numpy import pi

dat, fname = get_data(sys.argv)

print('Plotting')

# grab the data fields we want from the pickle file
time1 = dat['/v_meas']['t']
v_meas = dat['/v_meas']['data']

time2 = dat['/v_ref']['t']
v_ref = dat['/v_ref']['data']

plt.plot(time1, v_meas)
plt.plot(time2, v_ref)
plt.title('Velocity and Reference vs. Time')
plt.ylabel('Velocity Estimate [m/s]')
plt.xlabel('Time [s]')
plt.show()

