class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        unordered_map<int, int> color;
        
        stack<int> s;
        unordered_set<int> visited;

        for (int i = 0; i < graph.size(); ++i) {

            if (visited.count(i)) continue;

            s.push(i);
            color[i] = 0;

            while (!s.empty()) {
                int u = s.top();
                visited.insert(u);
                s.pop();
                for (int v : graph[u])
                    if (visited.count(v) <= 0) color[v] = !color[u], s.push(v);
                    else if (color[v] == color[u]) return false;
            }
        }
        
        return true;
    }
};
