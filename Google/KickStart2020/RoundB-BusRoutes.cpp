#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_days(vector<ll>& v, ll d) {
    ll h = d;
    for (int i = 0; i < v.size(); ++i) {
        if (h <= v[i]) h = v[i];
        else if (h % v[i] == 0) {}
        else h = v[i] * ((h/v[i]) + 1);
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        ll n, d; cin >> n >> d;

        vector<ll> v(n);

        for (int i = 0; i < n; ++i) cin >> v[i];

        ll l = 1;
        ll r = 10e12;

        while (l < r) {
            ll m = l + (r-l) / 2;

            if (get_days(v, m) > d) r = m;
            else l = m + 1;
        }

        cout << "Case #" << t+1 << ": " << l-1 << endl;
    }
}
