clc;
clear;

[absolute, first, second] = mInput();
nodes = input('Enter the number of nodes: ');
nodes = absolute/(nodes - 1);

x = first : nodes : second;
func = sin(x);
points = linspace(x(1), x(end), 100);
polynomNewton = mNewton(x, func, points);

figure
fplot(@sin, [first second])
hold on
plot(x, func, 'ko', points, polynomNewton)
