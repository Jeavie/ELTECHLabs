% clc;
% clear;
% m = 0;
% n = 3;
% s = 1 : 1000;
% empty_matrix = zeros(1, length(s));
% for i = s
%     random_matrix = betarnd(1, 1, i);
%     maximum = max(max(abs(inv(random_matrix)*random_matrix - eye(size(random_matrix)))));
%     empty_matrix(i) = maximum;
% end
% max(empty_matrix)
% plot (s, empty_matrix, '*');

clc;
clear;
m = 0;
n = 3;
while m <= 0.1
    for i = 1 : n
        matrix(i, 1) = ones(size(n));
        matrix(i, 2) = randi(50);
    end
    for j = 3 : n
        for i = 1 : n
            matrix(i, j) = matrix(i, 2) ^ (j - 1);
        end
    end
    mat = matrix * inv(matrix) - eye(n);
    m = max(max(mat))
    n = n + 1;
end
n