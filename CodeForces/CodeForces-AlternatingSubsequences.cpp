#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) cin >> v[i];

        bool positive = v[0] > 0;

        ll s = 0;
        int m = v[0];

        for (int i = 1; i < n; ++i) {
            if (positive) {
                if (v[i] > 0) {
                    m = max(m, v[i]);
                } else {
                    s += m;
                    m = v[i];
                    positive = !positive;
                }
            } else {
                if (v[i] < 0) {
                    m = max(m, v[i]);
                } else {
                    s += m;
                    m = v[i];
                    positive = !positive;
                }
            }
        }

        s += m;

        cout << s << endl;
    }
}
