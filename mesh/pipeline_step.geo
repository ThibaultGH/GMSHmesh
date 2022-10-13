H = 5;
L = 50;
l = 20;
h = 2.5;
lc = 0.1;

Point(1) = {0,H,0,lc};
Point(2) = {0,h,0,lc};
Point(3) = {l,h,0,lc};
Point(4) = {l,0,0,lc};
Point(5) = {L,0,0,lc};
Point(6) = {L,H,0,lc};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,5};
Line(5) = {5,6};
Line(6) = {6,1};

Line Loop(0) = {1,2,3,4,5,6};
Plane Surface(0) = {0};
Physical Line(0) = {0};
