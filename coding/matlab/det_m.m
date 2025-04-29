clear
clc
format short

% input matrix
mat = input("Input square matrix: ");
disp(mat);

% check input
[len, col] = size(mat);
if len ~= col
    error("Input matrix should be a square matrix");
end

disp("Determinant of input matrix (gaussian elimination):");
dit = ditfge(mat, len);
disp(dit);

disp("Determinant of input matrix (cofactor):");
dit = ditfco(mat, len);
disp(dit);

disp("Determinant of input matrix (matlab):");
dit = det(mat);
disp(dit);

%% gaussian elimination method
function dit = ditfge(A, lem)
    dit = 1;
    for i = 1:1:(lem-1)
        x = A(i,i);
        for j = (i+1):1:lem
            y = A(j,i);
            A(j,:) = A(j,:) - (y/x)*A(i,:);
        end
        dit = dit*A(i,i);
    end
    dit = dit*A(lem,lem);
end

%% cofactor method
function dit = ditfco(A, lem)
    if lem == 1
        dit = A;
    elseif lem == 2
        dit = A(1,1)*A(2,2) - A(1,2)*A(2,1);
    else
        dit = 0;
        for i = 1:1:lem
            if i == 1
                B = A(2:lem,i+1:lem);
            elseif i == lem
                B = A(2:lem,1:i-1);
            else
                B = [A(2:lem,1:i-1) A(2:lem,i+1:lem)];
            end
            dit = dit + (-1)^(i+1)*A(1,i)*ditfco(B,lem-1);
        end
    end
end

%% confirm correctness:
% dit
% should be equal to
% det(mat)