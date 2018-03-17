clc;
clear;
first = input('Please enter the first number: ' );
second = input('Please enter the second number \n(Make sure the difference between them is more than 7): ' );
a = abs(first - second);
if and (first < second, a > 7)
    x = first : 2 : second;
    y=sin(x);
    nodes = ceil((second - first)/2);
    fact = factorial(nodes);
    xx=linspace(first, second, 100);
    yy=mLagrange(x, y, xx);
    figure
    fplot(@sin,[first second])
    hold on
    plot(xx, yy, 'm')
    plot(x, y, 'ko')
    legend('sin', 'polynom')
    r = first + (second - first) * rand;
    rr = mLagrange(x, y, r);
    random_error = abs(sin(r) - rr)
    n=linspace(first, second, nodes);
    theor_error = max(abs((second - first)^(lenghtCheb + 1) * prod (n-r) * sin(x + (pi/2)*rem(length(x), 5))) /fact)
else
    disp('Error: invalid values');
end