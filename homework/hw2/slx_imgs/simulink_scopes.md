### Simulink Block Diagram

![](./simulink_mdl.png)

### Input case 1

![](./first_case.jpg)

### Input case 2

![](./second_case.jpg)

### Discrete PI Controller Function

`controller.m`

```matlab
function u = controller(e, d_t)

    % control gains
    kp = 2;
    ki = 1;

    persistent integral
    if isempty(integral)
        integral = 0;
    end
    integral = integral + e*d_t;

    u = kp*e + ki*integral;
end
```



