#pragma GCC optimize("03")

#include <bits/stdc++.h>

using namespace std; 

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        unordered_set<string> P;
        vector<string> V(n);
        vector<int> S;
        int c;
        for (int i = 0; i < n;++i) {
            string p; cin >> p;
            if (P.count(p) > 0) S.push_back(i);
            else P.insert(p);
            V[i] = p;
        }

        c = S.size();

        for (int i: S) {
            string& p = V[i];
            while (P.count(p) > 0) {
                int k = p.back() - '0';
                k = (k + 1) % 10;
                char c = '0' + k;
                p[p.size() - 1] = c;
            }
            P.insert(p);
        }

        cout << c << endl;
        for (const string& s: V) cout << s << endl;
    }
    return 0;
}