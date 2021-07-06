clear
clc 
A=[1 -4 -2 21; 2 1 2 3; 3 2 -1 -2];

[R, ~] = size(A);
for i=1:R
    A(i, :) = A(i, :) / A(i, i);
    r=1:R; r(i) = [];
    for j=1:R-1
        A(r(j), :) = A(r(j), :) - A(r(j), i) * A(i, :);
    end
end
X = A(:,end);
X