class Solution {
public:
    int numDistinct(const string& s, const string& t) {
        if (t.size() > s.size()) {
            return 0;
        }
        
        if (t == s) {
            return 1;
        }
        
        int MOD = 1e9+7;
        
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));
        
        dp[0][0] = t[0] == s[0];
        
        for (int i = 1; i < s.size(); ++i) {
            dp[i][0] = (s[i] == t[0]) + dp[i-1][0];
        }
        
        for (int i = 1; i < t.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[j] == t[i]) {
                    dp[j][i] = (dp[j-1][i]%MOD) + (dp[j-1][i-1]%MOD)%MOD;
                } else {
                    dp[j][i] = dp[j-1][i];
                }
            }
        }
        
        return dp[s.size() - 1][t.size() - 1];
    }
};
