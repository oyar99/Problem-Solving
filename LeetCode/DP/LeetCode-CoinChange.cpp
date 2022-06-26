class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(2, vector<int>(amount + 1, INT32_MAX - 1));
        
        for (int i = 0; i < amount + 1; ++i) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < amount + 1; ++j) {
                if (j - coins[i] < 0) {
                    dp[1][j] = dp[0][j];
                } else {
                    dp[1][j] = min(dp[0][j], dp[1][j - coins[i]] + 1);
                }
            }
            
            dp[0].swap(dp[1]);
        }
        
        return dp[0][amount] == (INT32_MAX - 1) ? -1 : dp[0][amount];
    }
};
