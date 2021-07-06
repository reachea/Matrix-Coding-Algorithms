clear;
clc;
A = [-1,8,-2;-6,49,-10;-4,34,-5];
[R,~] = size(A);
I = A;
for i=1:R
    I(i, i) = 1;
    r=1:R; r(i) = [];
    for j=1:R-1
        I(i, r(j)) = 0;
    end
end
B = [A I];

for i=1:R
    B(i, :) = B(i, :) / B(i, i);
    r=1:R; r(i) = [];
    for j=1:R-1
        B(r(j), :) = B(r(j), :) - B(r(j), i) * B(i, :);
    end
end
B