clear
clc
format short

% coefficient matrix
coe = input("Input coefficient matrix: ");
disp(coe);
% source matrix
sou = input("Input source matrix: ");
disp(sou);

% check input
[rowC, colC] = size(coe);
[rowS, colS] = size(sou);
if rowC ~= colC
    error("coefficient matrix should be a square matrix");
elseif colS ~= 1
    error("source matrix should be a column matrix");
elseif rowS ~= rowC
    error("length of source matrix should equal to length of coefficient matrix");
else
    len = rowS;
end

% augmented matrix
aug = [coe sou];
disp("The augmented matrix:")
disp(aug);

% upper triangular augmented matrix
% i - columns, j - row elements in column i
% 1st loop loops through the diagonal values (i,i)
% 2nd loop sets column values below the diagonal values to 0
for i = 1:1:(len-1)
    x = aug(i,i);
    for j = (i+1):1:len
        y = aug(j,i);
        aug(j,:) = aug(j,:) - (y/x)*aug(i,:);
    end
end
disp("Upper triangular augmened matrix:");
disp(aug);

% backward substitution
sol = zeros(len, 1);
for k = len:-1:1
    som = aug(k,k+1:len) * sol(k+1:len);
    sol(k,1) = (aug(k,len+1) - som) ./ aug(k,k);
end
disp("The solution matrix:")
disp(sol);

%% confirm correctness:
% sol
% should be equal to
% rref([coe sou])