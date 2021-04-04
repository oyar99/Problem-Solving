class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Create pairs (Xi, Yi) such that Xi corresponds to the number of zeros and Yi to the number of ones in the ith string
        // Find length of longest subsequence such that ΣXi <= m and ΣYi <= n
        // Problem can be reduced to a special kind of LIS
        // Sort sequence by Xi and solve LIS
        // Sort sequence by Yi and solve LIS
        // Return the best result
        // Time complexity: O(n^2) where n is number of strings
        vector<vector<int>> v;
        
        for (const string& s : strs) {
            int ones = 0;
            
            for (char c : s) 
                if (c == '1') ++ones;
            
            int zeroes = s.size() - ones;
        
            v.push_back({ zeroes, ones});
        }
        
        int ans = 0;
        
        auto f = [&]() {
            int N = v.size();

            int dp[N];
            memset(dp, 0, sizeof(dp));
            unordered_map<int, pair<int, int>> mp;

            for (int i = 0; i < N; ++i) {

                if (v[i][0] <= m && v[i][1] <= n) {
                    dp[i] = 1;
                    ans = max(ans, dp[i]);
                    mp[i] = {v[i][0], v[i][1]};
                }

                for (int j = i - 1; j >= 0; --j) {
                    if (v[i][0] + mp[j].first <= m && v[i][1] + mp[j].second <= n && dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        mp[i] = { v[i][0] + mp[j].first, v[i][1] + mp[j].second };
                        ans = max(ans, dp[i]);
                    }
                }
            }
        };
        
        sort(v.begin(), v.end(), [](auto & a, auto & b) {
            if (a[0] == b[0]) return a[1] < b[1];

            return a[0] < b[0];
        });
        
        f();
        
        sort(v.begin(), v.end(), [](auto & a, auto & b) {
            if (a[1] == b[1]) return a[0] < b[0];

            return a[1] < b[1];
        });
        
        f();
        
        return ans;
    }
};
