#include <bits/stdc++.h>

using namespace std;

#define EPS 10e-9

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int W, H, L, U, R, D; cin >> W >> H >> L >> U >> R >> D;
        
        double dp[301][301];
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;

        auto is_inside = [&] (int x, int y) {
            return x >= U && x <= D && y >= L && y <= R;
        };

        if (W == 1 || H == 1) {
            printf("Case #%d: %.5f\n", t+1, 0.0f);
            continue;
        }

        double ans = 0;

        for (int i = 2; i <= H; ++i) {
            if (is_inside(i-1, 1)) dp[i][1] = 0; 
            else dp[i][1] = 0.5 * dp[i-1][1];

            if (is_inside(i, 1)) ans += dp[i][1];
        }

        for (int j = 2; j <= W; ++j) {
            if (is_inside(1, j - 1)) dp[1][j] = 0;
            else dp[1][j] = 0.5 * dp[1][j-1];

            if (is_inside(1, j)) ans += dp[1][j];
        }

        for (int i = 2; i <= H; ++i) {
            for (int j = 2; j <= W; ++j) {
                double l = is_inside(i, j - 1) ? 0: (i == H ? 1:0.5) * dp[i][j-1];
                double u = is_inside(i-1, j) ? 0: (j == W ? 1: 0.5) * dp[i-1][j];

                dp[i][j] = l + u;
                
                if (is_inside(i, j)) {
                    ans += dp[i][j];
                }
            }
        }


        printf("Case #%d: %.5f\n", t+1, 1 - ans);
    }
}
