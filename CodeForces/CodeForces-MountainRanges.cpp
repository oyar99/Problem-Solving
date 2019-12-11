#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> m(n);

    for (int i = 0; i < n;++i) {
        int h; cin >> h;
        m[i] = h;
    }

    int mx = 0;
    for (int i = 0; i < n;++i) {
        int h = 0;
        int j;
        for (j = i; j < n - 1; ++j) {
            h += m[j+1] - m[j];

            if (m[j+1] - m[j] > x) break;
        }
        mx = max(mx, j - i + 1);
    }

    cout << mx << endl;
}