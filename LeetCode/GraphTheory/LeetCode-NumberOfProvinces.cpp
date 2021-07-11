class Solution {
public:
    void dfs(vector<vector<int>>& graph, int u, unordered_set<int>& visited) {
        
        visited.insert(u);
        
        for (int v = 0; v < graph.size(); ++v) {
            if (u == v || visited.count(v)) continue;
            if (graph[u][v]) {
                dfs(graph, v, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        unordered_set<int> visited;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited.count(i)) {
                dfs(isConnected, i, visited);
                ++ans;
            }
        }
        
        return ans;
    }
};
