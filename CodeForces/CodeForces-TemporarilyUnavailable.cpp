#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int a, b, c, r; cin >> a >> b >> c >> r;

        if (a > b) swap(a, b);
        int m = 0;

        if (c + r <= a || c - r >= b) m = b - a;
        else if (c - r >= a && c + r <= b) m = b - a - 2 * r;
        else if (c -r <= a && c + r >= b) m = 0;
        else if (c - r > a) m = (c - r) - a;
        else m = b - (c + r);

        cout << m << endl;
    }
}