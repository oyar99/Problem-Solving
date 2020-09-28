#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[2500][2500];
ll MOD = 9999959999;

ll solve(int u, int v) {
    if (u == 0 && v == 0) return 1;
    if (u == 0) return v + 1;

    if (memo[u][v] != -1) return memo[u][v];

    ll ans = 1;
    if (u > 0) ans = ((ans % MOD) + solve(u-1, v+1) % MOD) % MOD;
    if (v > 0) ans = ((ans % MOD) + solve(u,v-1) % MOD) % MOD;
    memo[u][v] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof(memo));

    while (1) {

        int l, s; cin >> l >> s;

        if (l == 0 && s == 0) break;

        ll ans = solve(l, s);

        cout << ans << endl;
    }
}
