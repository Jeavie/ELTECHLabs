clc;
clear;

func = @(x) 500/(x.^2 + 4 * x + 28);
ifunc = 30.3249398392564;

n = 1 : 100;
maximum = max(n);
plotAlpha1 = zeros(size(n));
plotAlpha2 = zeros(size(n));
plotAlpha3 = zeros(size(n));
plotAlpha4 = zeros(size(n));

for i = n
    
    points = linspace(0, 2, i + 1);
    h = points(i + 1) - points(i);
    
% % % % %  интеграл по левым точкам прямоугольника
    for j = 1 : i
        int1(j) = func(points(j)) * h;
    end
    sum1(i) = sum(int1);
    delta1 = abs(ifunc - sum1(i));
    alpha1 = -log(delta1)/log(i);
    plotAlpha1(i) = alpha1;

% % % % %  интеграл по средним точкам прямоугольника
    for j = 1 : i
        int2(j) = func(points(j) + (h / 2)) * h;
    end
    sum2(i) = sum(int2);
    delta2 = abs(ifunc - sum2(i));
    alpha2 = -log(delta2)/log(i);
    plotAlpha2(i) = alpha2;

% % % % %  интеграл по трапециям
    for j = 1 : i
        int3(j) = ((func(points(j)) + func(points(j + 1))) / 2) * h;
    end
    sum3(i) = sum(int3);
    delta3 = abs(ifunc - sum3(i));
	alpha3 = -log(delta3)/log(i);
	plotAlpha3(i) = alpha3;
    
    % % % % %  интеграл по формуле Симпсона
    for j = 1 : i
        int4(j) = (func(points(j)) + 4 * func((points(j + 1) + points(j)) / 2) + func(points(j + 1))) * (points(j + 1) - points(j)) / 6;
    end
    sum4(i) = sum(int4);
    delta4 = abs(ifunc - sum4(i));
    alpha4 = -log(delta4)/log(i);
    plotAlpha4(i) = alpha4;
end

plot (n, plotAlpha1, 'm');
hold on
plot (n, plotAlpha2, 'b');
plot (n, plotAlpha3, 'r');
plot (n, plotAlpha4, 'k');
legend('alpha 1 -> 1', 'alpha 2 -> 2', 'alpha 3 - > 2', 'alpha 4 -> 5');
