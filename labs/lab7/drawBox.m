% Author: Tony Zheng 
% This function draws the box with an arrow
function drawBox(l, w, h, b, rot , c)
%l = half length 
%w = half width 
%h = half height 
%b = coordinates of the body in world frame
%l=l+0.1*l;

%top
p1 = b+rot*[-w l h]';
p2 = b+rot*[-w -l h]';
p3 = b+rot*[+w -l h]';
p4 = b+rot*[+w +l h]';
x = [p1(1) p2(1) p3(1) p4(1)];
y = [p1(2) p2(2) p3(2) p4(2)];
z = [p1(3) p2(3) p3(3) p4(3)];
fill3(x, y, z, c); 

%bottom
p1 = b+rot*[-w +l -h]';
p2 = b+rot*[-w -l -h]';
p3 = b+rot*[+w -l -h]';
p4 = b+rot*[+w +l -h]';
x = [p1(1) p2(1) p3(1) p4(1)];
y = [p1(2) p2(2) p3(2) p4(2)];
z = [p1(3) p2(3) p3(3) p4(3)];
fill3(x, y, z, c); 

%back face
p1 = b+rot*[-w +l +h]';
p2 = b+rot*[-w +l -h]';
p3 = b+rot*[-w -l -h]';
p4 = b+rot*[-w -l h]';
x = [p1(1) p2(1) p3(1) p4(1)];
y = [p1(2) p2(2) p3(2) p4(2)];
z = [p1(3) p2(3) p3(3) p4(3)];
fill3(x, y, z, c); 

%front face
p1 = b+rot*[+w l h]';
p2 = b+rot*[+w l -h]';
p3 = b+rot*[+w -l -h]';
p4 = b+rot*[+w -l h]';
x = [p1(1) p2(1) p3(1) p4(1)];
y = [p1(2) p2(2) p3(2) p4(2)];
z = [p1(3) p2(3) p3(3) p4(3)];
fill3(x, y, z, c); 

%left
p1 = b+rot*[+w l +h]';
p2 = b+rot*[+w l -h]';
p3 = b+rot*[-w l -h]';
p4 = b+rot*[-w l +h]';
x = [p1(1) p2(1) p3(1) p4(1)];
y = [p1(2) p2(2) p3(2) p4(2)];
z = [p1(3) p2(3) p3(3) p4(3)];
fill3(x, y, z, c); 

%right face
p1 = b+rot*[+w -l +h]';
p2 = b+rot*[+w -l -h]';
p3 = b+rot*[-w -l -h]';
p4 = b+rot*[-w -l +h]';
x = [p1(1) p2(1) p3(1) p4(1)];
y = [p1(2) p2(2) p3(2) p4(2)];
z = [p1(3) p2(3) p3(3) p4(3)];
fill3(x, y, z, c); 

%arrow
p1 = b+rot*[0 -l h]';
p2 = b+rot*[w 0 h]';
p3 = b+rot*[0 l h]';
p4 = b+rot*[0 0.5*l h]';
p5 = b+rot*[-w 0.5*l h]';
p6 = b+rot*[-w -0.5*l h]';
p7 = b+rot*[0 -0.5*l h]';
x = [p1(1) p2(1) p3(1) p4(1) p5(1) p6(1) p7(1)];
y = [p1(2) p2(2) p3(2) p4(2) p5(2) p6(2) p7(2)];
z = [p1(3) p2(3) p3(3) p4(3) p5(3) p6(3) p7(3)];
fill3(x, y, z, 'b'); 

end