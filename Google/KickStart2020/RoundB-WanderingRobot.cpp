#include <bits/stdc++.h>

using namespace std;

#define EPS 10e-9

typedef long long ll;

//This solution has a run time complexity of O(W*H) which results inefficient for large data sets.

int main() {

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int W, H, L, U, R, D; cin >> W >> H >> L >> U >> R >> D;
        
        double dp[301][301];
        memset(dp, 0, sizeof(dp));
        dp[H][W] = 1.0;

        auto is_inside = [&] (int x, int y) {
            return x >= U && x <= D && y >= L && y <= R;
        };

        for (int i = H - 1; i >= 1; --i) {
            if (is_inside(i, W)) break;
            dp[i][W] = dp[i+1][W];
        }

        for (int j = W - 1;j >= 1; --j) {
            if (is_inside(H, j)) {
                break;
            }
            dp[H][j] = dp[H][j+1];
        }

        for (int i = H - 1; i >= 1; --i) {
            for (int j = W - 1; j >= 1; --j) {
                if (is_inside(i, j)) continue;
                dp[i][j] = dp[i+1][j] * 0.5 + dp[i][j+1] * 0.5;
            }
        }

        printf("Case #%d: %.6f\n", t+1, dp[1][1]);
    }
}
