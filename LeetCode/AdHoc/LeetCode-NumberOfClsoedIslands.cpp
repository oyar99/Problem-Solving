struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        int a = v.first;
        int b = v.second;
        return a >= b ? a * a + a + b : a + b * b;
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        unordered_set<pair<int, int>, pair_hash> visited;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                if (grid[i][j] == 1) continue;
                
                
                if (visited.count({i, j}) <= 0) {
                    
                    bool valid = true;
                    
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    
                    while (!s.empty()) {
                        pair<int, int> u = s.top();
                        s.pop();
                        
                        if (visited.count(u) <= 0) {
                            
                            if (u.first == 0 || u.first == n - 1 || u.second == 0 || u.second == m - 1) {
                                valid = false;
                            }
                            
                            visited.insert(u);
                        
                            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

                            for (const auto& dir : directions) {
                                pair<int, int> v = {u.first + dir.first, u.second + dir.second};
                                
                                if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m) continue;

                                if (grid[v.first][v.second] == 0) {
                                    s.push({v.first, v.second});
                                }
                            }
                            
                        }
                    }
                    
                    if (valid) ++count;
                    
                }
            }
        }
        
        return count;
    }
};
