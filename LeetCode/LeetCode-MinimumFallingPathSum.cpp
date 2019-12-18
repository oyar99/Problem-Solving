class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        if (A.size() == 1) {
            int m = INT32_MAX;
            for (int i = 0; i < A[0].size();++i) m = min(m, A[0][i]);
            return m;
        }
        
        vector<vector<int>> dp(A.size(), vector<int>(10000, 1e6));
        
        for (int i = 0; i < A[A.size() - 1].size();++i) dp[A.size() - 1][i] = A[A.size() - 1][i];
        
        for (int i = A.size() - 2; i >= 0; --i) {
            for (int j = 0; j < A[i].size();++j) {
                if (j > 0 && j + 1 < A[i+1].size()) dp[i][j] = min(min(dp[i+1][j-1], dp[i+1][j]), dp[i+1][j+1]) + A[i][j];
                else if (j + 1 == A[i+1].size()) dp[i][j] = min(dp[i+1][j-1], dp[i+1][j]) + A[i][j];
                else if (j == 0 && j +1 < A[i+1].size()) dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + A[i][j];
                else dp[i][j] = A[i][j];
            }
        }
        
        int m = INT32_MAX;
        for (int i = 0; i < A[0].size(); ++i) m = min(m, dp[0][i]);
        return m;
    }
};