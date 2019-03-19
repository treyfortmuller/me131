# a test script for moving average of velocity measurements with python lists
# Trey Fortmuller

vel_series = [0.0] * 10

example_data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

for v_est in example_data:
	# shift all the elements of vel_series popping the last one
	# and replacing the first element with the new measurement
	vel_series.pop() # pops the last item in the list
	vel_series.insert(0, v_est) # insert the latest estimate at the front of the list

	print(vel_series)

	# reported measurement for control is an average of 10 measurements
	v_meas = sum(vel_series)/len(vel_series)

	print("avg: " + str(v_meas))
