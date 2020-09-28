class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        if (grid[0][0] == 1) return 0;
        
        vector<vector<long long>> dp(grid.size(), vector<long long>(grid[0].size()));
        
        bool fw = true;
        for (int i = 0; i < grid.size(); ++i) {
            dp[i][0] = !grid[i][0] && fw;
            
            if (grid[i][0]) fw = false;
        }
        fw = true;
        for (int i = 0; i < grid[0].size();++i) {
            dp[0][i] = !grid[0][i] && fw;
            
            if (grid[0][i]) fw = false;
        }
        
        for (int i = 1; i < grid.size();++i) {
            for (int j = 1; j < grid[i].size();++j) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};