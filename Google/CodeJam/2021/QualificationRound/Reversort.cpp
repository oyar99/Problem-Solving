#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        int cost = 0;

        for (int i = 0; i < n - 1; ++i) {
            int m = INT32_MAX;
            int k;
            for (int j = i; j < n; ++j) {
                if (v[j] < m) {
                    m = v[j];
                    k = j;
                }
            }

            reverse(v.begin() + i, v.begin() + k + 1);

            cost += (k - i + 1);

        }
        cout << "Case #" << (t + 1) << ": " << cost << endl;
    }
}
