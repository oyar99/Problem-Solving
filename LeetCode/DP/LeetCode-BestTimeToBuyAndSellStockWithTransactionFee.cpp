class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       //dp[i][0] is best profit up to ith day if you do not own a stock
       //dp[i][1] is best profit up to ith day if you own a stock
        
        int n = prices.size();
        int dp[n][2];
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        
        // Intuitively, it would not be optimal if you own a stock on the last day
        return dp[n-1][0];
    }
};
