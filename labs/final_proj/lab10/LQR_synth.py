'''
A script for computing the LQR optimal gain matrix K for the reference tracking LQR
lane keeping controller on the BARC
'''

from __future__ import print_function, division

import controlpy # mark's python control library
import numpy as np

# system dynamics matrices in continuous time
Ac = np.matrix([[0,1],[0,0]])
Bc = np.matrix([[0],[1]])

# define our cost matrices
Q = np.matrix([[1,0],[0,0]])
R = np.matrix([[1]])

# define the sampling time of the discrete controller
dt = 0.0333 # 30 frames per second?

# compute the LQR controller
K, X, clEigVals = controlpy.synthesis.controller_lqr_discrete_from_continuous_time(Ac,Bc,Q,R, dt)

print('The computed gain matrix is:')
print(K)

print('The closed loop eigenvalues are:')
print(clEigVals)



