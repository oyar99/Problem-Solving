class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        // dp(i, 0) is the length of the longest wiggle subsequence starting at index i, and the first difference is negative
        // dp(i, 1) is the length of the longest wiggle subsequence starting at index i, and the first difference is positve
        
        // dp(i, 0) = max(dp(i + j, 1)) + 1 for all j such that nums[j] - nums[i] < 0 && j > i
        // dp(i, 1) = max(dp(i + j, 0)) + 1 for all j such that nums[j] - nums[i] > 0 && j > i
        
        // final answer will be the maximum value for all i in dp(i, 0) and dp(i, 1);
        int dp[n][2];
        
        dp[n-1][0] = dp[n-1][1] = 1;
        
        int ans = 1;
        
        for (int i = n - 2; i >= 0; --i) {
            dp[i][0] = dp[i][1] = 0;
            
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                else if (nums[i] < nums[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        
        return ans;
    }
};
