#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, c; cin >> n >> c;

        if (c < n - 1 || c > n * (n + 1) / 2 - 1) {
            cout << "Case #" << (t + 1) << ": IMPOSSIBLE" << endl;
            continue;
        }

        vector<int> v(n, - 1);

        int s = 0;
        int f = -1;
        int i;
        bool right = true;
        for (i = 0; i < n - 1; ++i) {
            int k = min(n - i, c - s - n + i + 2);

            s += k;

            if (k == 1) break;
            
            if (right) v[f + k] = i + 1, f = f + k;
            else v[f - k] = i + 1, f = f - k;

            right = !right;
        }

        int dir = right ? 1 : -1;

        for (int j = f + dir; j >= 0 && j < n && v[j] == -1; j = j + dir) {
            v[j] = ++i;
        }

        dir = dir * -1;

        for (int j = f + dir; j >= 0 && j < n && v[j] == -1; j = j + dir) {
            v[j] = ++i;
        }


        cout << "Case #" << (t + 1) << ": ";

        for (i = 0; i < n; ++i) {
            cout << v[i] << " ";
        }

        cout << endl;
    }
}
