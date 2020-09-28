#include <iostream>
#include <algorithm>

using namespace std;

const double PI = 3.1415;

int main() {
    #define int long long
    double R;
    int L;
    cin >> R >> L;
    double vol = (4.0 / 3.0) * (PI * R * R * R);
    int balloons = L / (int)vol;
    cout << balloons << endl;
    return 0;
}
