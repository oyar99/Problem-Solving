#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define INF (int)10e8+1
#define ll long long

ll dp1[(int)3e6+1];
ll dp2[(int)3e6+1];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, q; cin >> n >> q;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) cin >> v[i];

        dp1[0] = 0;
        dp2[0] = -INF;

        for (int i = 1; i <= n; ++i) dp1[i] = max(dp1[i-1], dp2[i-1] - v[i-1]), dp2[i] = max(dp2[i-1], dp1[i-1] + v[i-1]);

        cout << max(dp1[n], dp2[n]) << endl;
        
    }
}