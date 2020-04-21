    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long long ll;
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        int T; cin >> T;
     
        for (int t = 0; t < T; ++t) {
            ll n; cin >> n;
     
            ll x = -1;
            for (int i = 2; i < 31; ++i) {
                if (n % ((1 << i) - 1) == 0) {
                    x = n / ((1 << i) - 1);
                    break;
                }
            }
     
            cout << x << endl;
        }
    }
