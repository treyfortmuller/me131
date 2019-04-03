%This function takes the vector form of M and turns it into a skew symmetric matrix.
function Msym = skew_sym(M_vec)
Msym = [0 -M_vec(3) M_vec(2);
    M_vec(3) 0 -M_vec(1);
    -M_vec(2) M_vec(1) 0];
end