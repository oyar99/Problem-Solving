    #include <bits/stdc++.h>
     
    #define INF 10e8
     
    using namespace std;
     
    typedef long long ll;
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        int T; cin >> T;
     
        for (int t = 0; t < T; ++t) {
            int n, k; cin >> n >> k;
     
            vector<int> v(n);
     
            for (int i = 0; i < n; ++i) cin >> v[i];
     
            set<int> s;
     
            for (int i = 0; i < n; ++i) s.insert(v[i]);
     
            if (s.size() > k) {
                cout << -1 << endl;
                continue;
            }
     
            vector<int> ans;
     
            for (int v: s) ans.push_back(v);
     
            while (ans.size() < k) {
                ans.push_back(ans.back());
            }
     
     
            vector<int> temp;
            int m = 0;
            for (int i = 0;;) {
                if (i >= n || (!temp.empty() && temp.size() == k)) {
                    for (int j = 0; j < temp.size(); ++j) {
                        ans.push_back(temp[j]);
     
                        if (ans.size() >= 10000) break;
                    }
                    m = 0;
                    temp.clear();
                    if (i >= n) break;
                }
                if (i < n && ans[m] == v[i]) {
                    temp.push_back(v[i]);
                    ++i;
                }
                else {
                    temp.push_back(ans[m]);
                }
     
                ++m;
     
                if (ans.size() >= 10000) break;
            }
     
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
            cout << endl;
     
        }
    }
