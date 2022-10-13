R=1;
lc = 0.1;

Point(0) = {0,0,0,lc};
Point(1) = {R,0,0,lc};
Point(2) = {0,R,0,lc};
Point(3) = {-R,0,0,lc};
Point(4) = {0,-R,0,lc};

Circle(1) = {1,0,2};
Circle(2) = {2,0,3};
Circle(3) = {3,0,4};
Circle(4) = {4,0,1};

Line Loop(0) = {1,2,3,4};
Plane Surface(0) = {0};
Physical Line(0) = {0};