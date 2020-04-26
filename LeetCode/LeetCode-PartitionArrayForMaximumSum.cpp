
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        
        int n = A.size();
        
        int logs[501];
        logs[1] = 0;
        
        for (int i = 2; i < 501; ++i) logs[i] = logs[i>>1] + 1;
        
        int st[10][n];
        
        for (int i = 0; i < n; ++i) st[0][i] = A[i];
        
        for (int i = 1; i <= logs[n]; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                st[i][j] = max(st[i-1][j], st[i-1][j+(1 << (i-1))]);
            }
        }
        
        int dp[501];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j <= K; ++j) {
                if (i - j < 0) break;
                
                int len = (i - 1) - max(0, i - j) + 1;
                
                int m = max(st[logs[len]][max(0, i - j)], st[logs[len]][i - (1 << logs[len])]);
                
                dp[i] = max(dp[i], dp[i-j] + m * j);
            }
        }    
        return dp[n];
    }
};
