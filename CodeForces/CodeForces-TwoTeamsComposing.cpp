#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        vector<int> S(n);

        for (int i = 0; i < n; ++i) cin >> S[i];

        unordered_map<int, int> m;

        for (int i = 0; i < n; ++i) m[S[i]]++;

        int f = 0;
        int d = 0;

        for (const auto& e: m) {
            if (e.second > f) {
                f = e.second;
                d = e.first;
            }
        }

        unordered_set<int> s;

        for (int i = 0; i < n; ++i) {
            if (S[i] == d) continue;
            if (s.count(S[i]) <= 0) {
                s.insert(S[i]);
            }
        }

        if (s.size() >= f) cout << f << endl;
        else cout << max(min((int)s.size() + 1, f - 1), (int)s.size()) << endl;
    }
}
