clear
clc 
A=[1,-1,1,-1,-1;1,0,0,0,0;1,1,1,1,1;1,2,4,8,0];

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