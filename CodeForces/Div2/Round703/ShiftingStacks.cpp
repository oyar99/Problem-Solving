#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        string ans = "YES";
        ll prev = 0;
        for (ll i = 0; i < n; ++i) {
            ll h; cin >> h;
            ll carry = 0;

            if (i - 1 >= 0) carry = prev - (i - 1);
            
            if (i > 0 && (prev - carry >= carry + h)) ans = "NO";
            
            prev = carry + h;
        }

        cout << ans << endl;
    }
}
