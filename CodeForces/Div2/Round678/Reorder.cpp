#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        ll n, m; cin >> n >> m;

        ll s = 0;

        for (int i = 0; i < n; ++i) {
            ll v; cin >> v;

            s += v;
        }

        if (s == m) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}