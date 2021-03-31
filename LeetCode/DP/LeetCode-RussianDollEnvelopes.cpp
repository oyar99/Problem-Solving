class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [](auto & a, auto & b) {
            if (a[0] == b[0]) return a[1] < b[1];
            
            return a[0] < b[0];
        });
        
        int n = envelopes.size();
        
        int dp[n];
        int ans = dp[0] = 1;
        
        for (int i = 1; i < n; ++i) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
