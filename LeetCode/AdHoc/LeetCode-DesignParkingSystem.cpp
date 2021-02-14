class ParkingSystem {
    int b, m, s;
public:
    ParkingSystem(int big, int medium, int small) : b(big), m(medium), s(small) {}
    
    bool addCar(int carType) {
        return carType == 1 ? --b >= 0 : carType == 2 ? --m >= 0 : --s >= 0;
    }
};
