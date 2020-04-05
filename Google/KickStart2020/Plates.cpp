#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N, K, P; cin >> N >> K >> P;
        
        vector<vector<int>> plates(N, vector<int>(K));
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < K; ++j) cin >> plates[i][j];
        }

        vector<vector<int>> S(N, vector<int>(K+1));

        for (int i = 0; i < N; ++i) {
            vector<int> v(K+1);
            for (int j = 1; j < K+1; ++j) v[j] = v[j-1] + plates[i][j-1];
            S[i] = v;
        }
        //dp(i, j) is the maximum sum using i stacks and picking j plates in total
        vector<vector<int>> dp(N + 1, vector<int>(P+1));

        for (int i = 1; i < N + 1; ++i) {
            for (int j = 0; j < P + 1; ++j) {
                for (int x = 0; x < min(j+1, K+1); ++x) {
                    dp[i][j] = max(dp[i][j], S[i-1][x] + dp[i-1][j-x]);
                }
            }
        }
        cout << "Case #" << t << ": " << dp[N][P] << endl;
    }
}
