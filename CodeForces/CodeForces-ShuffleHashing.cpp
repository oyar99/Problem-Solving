#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for (int t = 0; t < T;++t) {
        string p, h; cin >> p >> h;

        if (h.size() < p.size()) {
            cout << "NO" << endl;
            continue;
        }

        unordered_map<char, int> m;

        for (int i = 0; i < p.size();++i) m[p[i]]++;

        unordered_map<char, int> c = m;

        
        string ans = "NO";
        for (int i = 0; i < h.size();++i) {
            int l = 0;
            for (int j = i; j < h.size(); ++j) {
                if (l == p.size()) {
                    ans = "YES";
                    break;
                }

                if (c[h[j]] > 0) {
                    c[h[j]]--;
                    ++l;
                } else {
                    c = m;
                    break;
                }
            }
            if (l == p.size()) ans = "YES";

            if (ans == "YES") break;
        }
        cout << ans << endl;
    }
}