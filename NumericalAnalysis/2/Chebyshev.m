clc;
clear;

[absolute, first, second] = mInput();

nodes = 5 : 20;
plotError = zeros(size(nodes)-4);
plotAlpha = zeros(size(nodes)-4);

for i = nodes
    
    quantityCheb = 0 : i - 1;
    nodesCheb = 0.5 * ((second - first) * cos((2 * quantityCheb + 1) / i * 0.5 * pi) + first + second);
    funcInCheb = sin(nodesCheb);
    lengthCheb = length(nodesCheb);
    fact = factorial(lengthCheb);
    
    points = linspace(first, second, 100);
    polynomNewton = mNewton(nodesCheb, funcInCheb, points);
    
    exactPoints = abs(second - first)/99;
    randomLinspace = unidrnd(101) - 1;
    randomPoint = first + randomLinspace * exactPoints;
    value = mNewton(nodesCheb, funcInCheb, randomPoint);
    
    errorCheb = abs(value - sin(randomPoint))
    plotError(i-4) = errorCheb;
    
    sinCheb = abs(max(sin(randomPoint + (pi/2) * (lengthCheb))));
    theorError = max(abs((second - first)^(lengthCheb) * sinCheb) /(fact * 2^(lengthCheb)))
    
    alpha = -log(errorCheb)/log(i);
    plotAlpha(i-4) = alpha;
end

plot (nodes, plotError, 'b');
hold on
plot (nodes, plotAlpha, 'm');
legend('error', 'alpha');

