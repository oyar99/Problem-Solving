class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int n = wall.size();
        
        unordered_map<int, int> m;
        
        for (int i = 0; i < n; ++i) {
            
            vector<int> P;
            
            P.push_back(wall[i][0]);

            for (int j = 1; j < wall[i].size(); ++j)
                P.push_back(P[j - 1] + wall[i][j]),
                m[P[j - 1]]++;
        }
        
        int inter = 0;
        
        for (const auto& e: m)
            inter = max(inter, e.second);
        

        return n - inter;
    }
};
