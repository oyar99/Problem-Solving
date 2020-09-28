#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T; cin >> T;

    for (int t = 1; t <= T; ++t) {
        int W; cin >> W;

        int dp[10000][16];
        memset(dp, 0, sizeof(dp));

        dp[1][15] = 1;
        dp[1][12] = 1;
        dp[1][6] = 1;
        dp[1][3] = 1;
        dp[1][0] = 1;

        for (int i = 1; i <= W; ++i) {
            dp[i][0] += dp[i-1][15];
            dp[i][3] += dp[i-1][15] + dp[i-1][12];
            dp[i][6] += dp[i-1][15] + dp[i-1][9];
            dp[i][9] += dp[i-1][6];
            dp[i][12] += dp[i-1][15] + dp[i-1][3];
            dp[i][15] += dp[i-1][15] + dp[i-1][12] + dp[i-1][6] + dp[i-1][3] + dp[i-1][0];
        }


        cout << t << " " << dp[W][15] << endl;
    }
}
