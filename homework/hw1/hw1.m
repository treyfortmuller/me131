% me131 homework 1 - Trey Fortmuller

%% problem 1 System Response

% A
sys = tf(1, [1, 1]);
step(sys);

% B
sys = tf(16, [1, 1.5, 16]);
step(sys);

% C
sys = tf([1, 4], [1, 1, 4]);
step(sys);

% D
sys = tf([5, -9], [1, 2.4, 9])
step(sys);

% E
sys = tf([-2, -9], [1, 1.5, 9])
step(sys)

% F
sys = tf([-3, 2], [1, 4, 2]);
step(sys);

% G
sys = tf([100000], [1, 305, 21500, 100000])
step(sys);


