struct ParkingSystem{int b,m,s;ParkingSystem(int b,int m,int s):b(b),m(m),s(s){}bool addCar(int c){return !--c?b-->0:!--c?m-->0:s-->0;}};
