class graph {
    private:
        unordered_map<int, unordered_set<int>> list;
    public:
        void add_vertex(int u) {
            list[u] = unordered_set<int>();
        }

        void add_edge(int u, int v) {
            list[u].insert(v);
            list[v].insert(u);
        }

        unordered_set<int> get_neighbours(int u) {
            return list[u];
        }
};


int build(graph& g, int u, vector<int>& data, vector<int>& w, unordered_set<int>& visited, vector<int>& parent) {
    if (visited.count(u) > 0) return 0;
    int sum = data[u-1];
    visited.insert(u);
    for (int v: g.get_neighbours(u)) {
        sum += build(g, v, data,w, visited, parent);
        parent[v] = u;
    }
    w[u] = sum;
    return sum;
}

int cutTheTree(vector<int>& data, vector<vector<int>>& edges) {
    graph g;
    
    for (int i = 1; i < data.size() + 1;++i) {
        g.add_vertex(i);
    }

    for (const auto& edge: edges) {
        g.add_edge(edge[0], edge[1]);
    }
    
    vector<int> w(data.size()+1);
    unordered_set<int> visited;
    vector<int> parent(data.size() + 1);
    build(g, 1, data, w,visited, parent);
    parent[1] = -1;
    int min_diff = INT32_MAX;
    for (const auto& edge: edges) {
        int u = edge[0];
        int v = edge[1];
        if (parent[v] != u) swap(u, v);
        u = 1;
        min_diff = min(min_diff, abs(w[v] - (w[u] - w[v])));

    }
    return min_diff;
}
