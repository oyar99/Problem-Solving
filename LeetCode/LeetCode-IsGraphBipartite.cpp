struct graph {
    unordered_map<int, unordered_set<int>> adj;
    
    void add_edge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }
};

bool is_bipartite(graph& g, int n) {
    queue<int> q;
    
    unordered_set<int> red;
    unordered_set<int> blue;
    unordered_set<int> visited;
    
    for (int w = 0; w < n; ++w) {
        
        if (visited.count(w) > 0) continue;
    
        red.insert(w);
        q.push(w);
        visited.insert(w);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (red.count(u) > 0) {

                for (int v: g.adj[u]) {
                    if (visited.count(v) <= 0) {
                        blue.insert(v);
                        visited.insert(v);
                        q.push(v);
                    }
                }

            } else {

                for (int v: g.adj[u]) {
                    if (visited.count(v) <= 0) {
                        red.insert(v);
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }  
        }
        
    }
    
    for (int u = 0; u < n; ++u) {
        if (red.count(u) > 0) {
            for (int v: g.adj[u]) {
                if (red.count(v) > 0) return false;
            }
        } else {
            for (int v: g.adj[u]) {
                if (blue.count(v) > 0) return false;
            }
        }
    }
    return true;
    
}

class Solution {
public:
    bool isBipartite(vector<vector<int>>& l) {
        
        graph g;
        
        for (int i = 0; i < l.size(); ++i) {
            for (int j = 0; j < l[i].size(); ++j) {
                g.add_edge(i, l[i][j]);
            }
        }
        
        return is_bipartite(g, l.size());
    }
};
