class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        // let n be the number of words
        // let m be the length of the longest word
        
        int n = words.size();
        
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        // longest chain starting at dp(i)
        int dp[1001];
        memset(dp, 0, sizeof(dp));
        
        int ans = 1;
        dp[n - 1] = 1;
        
        // O(n^2*m)
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = 1;
            
            for (int j = i + 1; j < n; ++j) {
                // compare two words
                
                if (words[j].size() == words[i].size()) continue;
                if (words[j].size() - words[i].size() > 1) break;
                
                int count[27];
                memset(count, 0, sizeof(count));
                
                int l = 0;
                
                for (int k = 0, p = 0; k < words[j].size(); ++k) {
                    if (words[j][k] == words[i][p]) {
                        ++l;
                        ++p;
                        continue;
                    }
                }
                
                assert(l <= words[j].size() - 1);
                
                if (l == words[j].size() - 1) dp[i] = max(dp[i], dp[j] + 1);
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
        
        
    }
};
