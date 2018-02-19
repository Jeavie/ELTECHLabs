clc;
clear;
s = 1 : 1000;
empty_matrix = zeros(1, length(s));
for i = s
    random_matrix = betarnd(1, 1, i);
    maximum = max(max(abs(inv(random_matrix)*random_matrix - eye(size(random_matrix)))));
    empty_matrix(i) = maximum;
end
max(empty_matrix)
plot (s, empty_matrix, '*');