#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; ++i)  cin >> v[i];

        int s = 0;

        for (int i = 0; i < n; ++i) s += v[i];

        if (s & 1) {
            cout << "YES" << endl;
        } else {
            vector<bool> odds(n+1, false);
            vector<bool> even(n+1, false);
            
            for (int i = n-1; i >= 0; --i) odds[i] = odds[i+1] || (v[i] & 1);
            for (int i = n-1; i>= 0; --i) even[i] = even[i+1] || (!(v[i] & 1));
            bool pos = false;
            for (int i = 0; i < n; ++i) {
                if (v[i] & 1) {
                    if (even[i]) {
                        pos = true;
                        break;
                    }
                    continue;
                }

                if (odds[i]) {
                    pos = true;
                    break;
                }
            }

            if (pos) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}