#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MOD 1000000007L

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, p; cin >> n >> x >> p;

    int perms[n];

    for (int i = 0; i < n; ++i) perms[i] = -1;

    perms[p] = 1;

    int smaller = x - 1;
    int greater = n - x;

    int l = 0;
    int r = n;

    while (l < r) {
        int m = (l + r) / 2;

        if (m == p) break;

        if (m > p) {
            perms[m] = max(0, greater--);
            r = m;
        }
        else {
            perms[m] = max(0, smaller--);
            l = m + 1;
        }
    }

    int nums = greater + smaller;

    for (int i = 0; i < n; ++i) {
        if (perms[i] == -1) perms[i] = max(0, nums--);
    }

    ll ans = 1;

    for (int i = 0; i < n; ++i) ans = ((ans % MOD) * (perms[i] % MOD)) % MOD;
    
    cout << ans << endl;

}
