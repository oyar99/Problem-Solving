#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int g[200][2];
int dp[200][201][3];

int main() {

    while (true) {
        int N, K; cin >> N >> K;

        if (N == 0 && K == 0) break;

        for (int i = 0; i < N; ++i) cin >> g[i][0] >> g[i][1];

        memset(dp, 0, sizeof(dp));

        dp[0][1][1] = g[0][0];
        dp[0][1][2] = g[0][1];

        for (int i = 0; i < N; ++i)
            for (int k = i + 1; k < K + 1; ++k)
                if (k == i + 1) 
                    dp[i][k][0] = 10000;
                else
                    for (int p : {0, 1, 2})
                        dp[i][k][p] = 10000;
                    
        for (int i = 1; i < N; ++i) {
            for (int k = 0; k < min(i + 2, K + 1); ++k) {
                dp[i][k][0] = min(dp[i-1][k][0], dp[i-1][k][1], dp[i-1][k][2]);

                if (k > 0) {
                    dp[i][k][1] = min(dp[i-1][k-1][0], dp[i-1][k-1][1]) + g[i][0];
                    dp[i][k][2] = min(dp[i-1][k-1][0], dp[i-1][k-1][2]) + g[i][1];
                }
            }
        }

        int value = 0;
        for (int i = 0; i < N; ++i) value += g[i][0] + g[i][1];

        cout << value - min(dp[N-1][K][0], dp[N-1][K][1], dp[N-1][K][2]) << endl;
    }
}
