class Solution {
public:
    int countHousePlacements(int n) {
        /*
        x x x x
        x x x x
        
        dp[i][0] represents the number of placements when there are i plots and the last column does not have
        houses
        dp[i][1] represents the number of placements when there are i plots and the last column only has one house at one side of the street
        dp[i][2] represents the number of placements when there are i plots and the last column only has one house at the other side of the street
        dp[i][3] represents the number of placements when there are i plots and the last column only has houses at both sides
        */
        const int MOD = 1e9+7;
        
        vector<vector<long long>> placements(n, vector<long long>(4, 1));
        
        for (int i = 1; i < n; ++i) {
            placements[i][0] = (placements[i-1][0]%MOD + placements[i-1][1]%MOD + placements[i-1][2]%MOD + placements[i-1][3]%MOD)%MOD;
            placements[i][1] = (placements[i-1][0]%MOD + placements[i-1][2]%MOD)%MOD;
            placements[i][2] = (placements[i-1][0]%MOD + placements[i-1][1]%MOD)%MOD;
            placements[i][3] = placements[i-1][0]%MOD;
        }
        
        long long ans = 0;
        
        for (int i = 0; i < 4; ++i) {
            ans = (ans%MOD + placements[n - 1][i]%MOD)%MOD;
        }
        
        return ans;
    }
};
