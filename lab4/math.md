**1.1** Acceleration Transfer Function
$$
G_{pwm} \rightarrow v(s) = \frac{-0.0943}{s-0.0001}
$$


**1.5** Steering Angle Formula
$$
L: \text{wheel base length}\\
\dot{\psi}: \text{yaw rate}\\
v: \text{vehicle speed}\\
\delta_f: \text{steering angle}
$$

$$
\dot{\psi} = \frac{2v}{L}\sin[\tan^{-1}(\frac{1}{2}\tan(\delta_f))]
$$

$$
\sin^{-1}(\frac{L\dot{\psi}}{2v}) = \tan^{-1}(\frac{1}{2}\tan(\delta_f))
$$

$$
2\tan(\sin^{-1}(\frac{L\dot{\psi}}{2v})) = \tan(\delta_f)
$$

$$
\delta_f = \tan^{-1}[2\tan(\sin^{-1}(\frac{L\dot{\psi}}{2v}))]
$$

