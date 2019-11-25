#pragma GCC Optmize("03")

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double H, L; cin >> H >> L;
    double A = 1.0/2.0 * ((L * L / H) - H);
    printf("%.6f", A);
    return 0;
}