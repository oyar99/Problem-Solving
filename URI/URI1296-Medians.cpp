#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {

    double a, b, c;
    double undefined = -1.0;
    while (cin >> a >> b >> c) {
        double s = (a + b + c) / 2;
        double p = (s * (s-a) * (s-b) * (s-c));

        if (p <= 0) {
            printf("%.3f\n", undefined);
        }
        else {
            double ans = (4.0/3.0) * sqrt(p);
            printf("%.3f\n", ans);
        }
    }

    return 0;
}