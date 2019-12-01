#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T;++t) {
        int r, g, b; cin >> r >> g >> b;

        int d = 0;

        if ((r >= g && r <= b) || (r >= b && r <= g)) {
            //R is mid element
            int dif = abs(b - g);

            if (b < g) {
                b += min(r, dif);
                r -= min(r, dif);
            } else {
                g += min(r, dif);
                r -= min(r, dif);
            }

            if (r > 0) {

                int h = r / 2;

                b += h;
                g += h+1;
            }

            d = min(b, g);

        } else if ((g >= r && g <= b) || (g >= b && b <= r)) {
            //G is mid element
            int dif = abs(r - b);

            if (r < b) {
                r += min(g, dif);
                g -= min(g, dif);
            } else {
                b += min(g, dif);
                g -= min(g, dif);
            }

            if (g > 0) {

                int h = g / 2;

                b += h;
                r += h + 1;
            }

            d = min(b, r);
        } else {
            //B is mid element
            int dif = abs(r - g);

            if (r < g) {
                r += min(b, dif);
                b -= min(b, dif);
            } else {
                g += min(b, dif);
                b -= min(b, dif);
            }

            if (b > 0) {
                int h = b / 2;
                
                r += h;
                g += h + 1;
            }

            d = min(r, g);
        }

        cout << d << endl;
    }

    return 0;
}