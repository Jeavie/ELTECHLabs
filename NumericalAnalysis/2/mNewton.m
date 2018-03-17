function newton = mNewton(x, func, points)

lnght = length(x);

for  i = 1 : lnght-1
    for j = 1: lnght - i
        func(j) = (func(j+1) - func(j)) / (x(j+i) - x(j));
    end
end

newton = func(1) * ones(size(points));

for i = 2 : lnght
    newton = func(i) + (points - x(i)) .* newton;
end