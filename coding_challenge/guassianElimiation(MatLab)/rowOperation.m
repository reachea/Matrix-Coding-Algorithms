clear;
clc;
A=[-4 5 -10 -7 6; 3 18 6 4 -5; 11 -10 -7 6 13; -9 13 8 17 -1; 17 12 -14 3 16];
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