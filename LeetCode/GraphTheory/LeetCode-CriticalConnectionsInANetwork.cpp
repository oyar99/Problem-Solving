class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        unordered_set<int> adj [100001];
        int discovered [100001];
        int low [100001];
        int parent [100001];
        
        vector<vector<int>> bridges;
        
        
        for (int i = 0; i < connections.size(); ++i) 
            adj[connections[i][0]].insert(connections[i][1]),
            adj[connections[i][1]].insert(connections[i][0]);
        
        for (int i = 0; i < n; ++i) discovered[i] = -1;
        
        
        int time = 0;
        
        std::function<void(int)> f = [&](int u) {
            discovered[u] = low[u] = ++time;
            
            for (int v: adj[u]) {
                if (discovered[v] == -1) {
                    parent[v] = u;
                    f(v);
                    
                    low[u] = min(low[u], low[v]);
                    
                    if (low[v] > discovered[u]) bridges.push_back({u, v});
                } else if (v != parent[u]) {
                    low[u] = min(low[u], discovered[v]);
                }
            }
        };
        
        f(0);
        
        return bridges;
    }
};
