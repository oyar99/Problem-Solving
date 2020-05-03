class Solution {
public:
    int numTilings(int N) {
        const int MOD = 1e9+7;
        int dp[N+1][4];
        
        memset(dp, 0, sizeof(dp));
        
        dp[1][3] = 1;
        dp[1][0] = 1;
        
        for (int i = 2; i <= N; ++i) {
            dp[i][0] = dp[i-1][3]%MOD;
            dp[i][1] = (dp[i-1][0]%MOD + dp[i-1][2]%MOD)%MOD;
            dp[i][2] = (dp[i-1][0]%MOD + dp[i-1][1]%MOD)%MOD;
            
            for (int j = 0; j < 4; ++j) dp[i][3] = (dp[i][3]%MOD + dp[i-1][j]%MOD) % MOD;
        }
        
        return dp[N][3]%MOD;
    }
};
