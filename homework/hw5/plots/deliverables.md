# ME131 HW5

Trey Fortmuller, 26037758

#### 1.1

```
sigma_max = 0.041
```

#### 1.2 - 1.4

(In Matlab)

#### 1.5

$$
\sigma^{des} = \frac{r_{w}\omega_{w}^{des} - V_{x}}{r_{w}\omega_{w}^{des}}\\
\Rightarrow r_{w}\omega_{w}^{des} = \frac{-V_{x}}{\sigma^{des} - 1}\\
\text{where}\ \sigma^{des} = \sigma_{max}
$$

#### 1.6

(In Matlab)

#### 1.7

The logic for activating the traction controller is based off the current slip ratio. If the current slip ratio is greater than the `sigma_max`, the slip ratio at which we achieve maximum tire traction force, then the controller activates and controls around a wheel speed which achieves `sigma_max`. If the current slip ratio is less than `sigma_max` then the controller deactivates and the driver dictates the engine torque directly.

#### 1.8

![](/home/trey/Semester 8/ME131/hw5/18plot.jpg)

#### 1.9

a) In Simulink: `NoTractionControl.slx`

b)

![](/home/trey/Semester 8/ME131/hw5/19b_plot.jpg)

The above plot for vehicle speed, measured wheel speed, and desired wheel speed shows that without traction control, the wheel speed drastically excedes the desired wheel speed. This indicates that wheels are running at a very high slip ratio, far beyond the optimal slip ratio for accelerating the vehicle. After 20 seconds, the wheel speed is ~12 times faster than the vehicle speed, we might call this a "burnout".

c)

![](/home/trey/Semester 8/ME131/hw5/19c_plot.jpg)

This result is reasonable, and it shows that our traction controller was effective in improving the acceleration of the vehicle. If two copies of the vehicle, one with traction control and one without, competed in a drag race, the vehicle with traction control would win.