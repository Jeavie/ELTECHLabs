function yy = mLagrange(x, y, xx)

n = length(x);
yy = zeros(size(xx));
for k = 1 : n
    matrix = ones(size(xx));
    for j = [1 : k-1, k+1 : n]
        matrix = matrix .* (xx-x(j)) / (x(k)-x(j));
    end
    yy = yy + y(k) * matrix;
end