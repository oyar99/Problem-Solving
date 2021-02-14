struct ParkingSystem{int b,m,s;ParkingSystem(int B,int M,int S){b=B;m=M;s=S;}bool addCar(int c){return !--c?b-->0:!--c?m-->0:s-->0;}};
