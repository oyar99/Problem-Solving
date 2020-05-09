#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) cin >> v[i];

        vector<int> p(n+1);

        for (int i = 0; i < n; ++i) p[i+1] = p[i] + v[i];

        unordered_map<int, int> m;

        for (int i = 0; i < n + 1; ++i) m[p[i]] = i;

        int count = 0;

        for (int i = 0; i < n; ++i) {
            bool found = false;
            for (int j = n; j >= 0; --j) {
                if (m.count(p[j] - v[i]) > 0) {

                    if (abs(m[p[j] - v[i]] - j) <= 1) continue;
                    found = true;
                    break;
                }
            }
            if (found) ++count;
        }

        cout << count << endl;
    }
}
