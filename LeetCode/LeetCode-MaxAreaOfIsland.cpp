struct graph {
    map<pair<int, int>, set<pair<int, int>>> list;
    
    void add_edge(pair<int, int> u, pair<int, int> v) {
        list[u].insert(v);
        list[v].insert(u);
    }
    
};

int dfs(graph& g, vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    set<pair<int, int>> visited;
    int area = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0) continue;
            if (visited.count({i, j}) > 0) continue;
            
            stack<pair<int, int>> s;
            int count = 0;
            s.push({i, j});
            
            while (!s.empty()) {
                pair<int, int> u = s.top();
                s.pop();
                
                if (visited.count(u) <= 0) {
                    visited.insert(u);
                    ++count;
                    
                    for (pair<int, int> v: g.list[u]) {
                        s.push(v);
                    }
                }
            }
            area = max(area, count);
        }
    }
    return area;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        graph g;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                if (grid[i][j] == 0) continue;
                
                if (j > 0 && grid[i][j-1] == 1) g.add_edge({i, j - 1}, {i, j}); //left
                if (i > 0 && grid[i-1][j] == 1) g.add_edge({i-1, j}, {i, j}); //up
                if (j + 1 < m && grid[i][j+1] == 1) g.add_edge({i, j + 1}, {i, j});//right
                if (i + 1 < n && grid[i+1][j] == 1) g.add_edge({i+1, j}, {i, j});//down
                
                
            }
        }
        
        int area = dfs(g, grid);
        
        return area;
        
    }
};
