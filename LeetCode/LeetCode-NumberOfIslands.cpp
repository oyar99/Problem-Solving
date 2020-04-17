
struct Graph {
    unordered_map<int, unordered_set<int>> list;
    int sz;
    
    Graph(int sz) {
        this->sz = sz;
    }
    
    void add_vertex(int u) {
        list[u] = unordered_set<int>();
    }
    
    void add_edge(int u, int v) {
        if (v <= 0 || v > sz) return;
        if (list.count(v) <= 0) return;
        list[u].insert(v);
        list[v].insert(u);
    }
};

int dfs(Graph& g) {
    
    int components = 0;
    unordered_set<int> visited;
    for (int w = 1; w <= g.sz; ++w) {
        
        if (visited.count(w) > 0) continue;
        if (g.list.count(w) <= 0) continue;
        
        ++components;
        
        stack<int> s;
        s.push(w);
        
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            
            if (visited.count(u) <= 0) {
                
                visited.insert(u);
                
                for (int v: g.list[u]) {
                    s.push(v);
                } 
            }
        }
    }
    return components;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.size() == 0) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int i = 1;
        Graph g(n*m);
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c, ++i) {
                if (grid[r][c] == '1') g.add_vertex(i);
            }
        } 
        
        i = 1;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c, ++i) {
                if (grid[r][c] == '0') continue;
                
                if (c != 0) g.add_edge(i, i - 1);
                if (c != m - 1) g.add_edge(i, i + 1);
                g.add_edge(i, i + m);
                g.add_edge(i, i - m);
            }
        }
        return dfs(g);
    }
};
