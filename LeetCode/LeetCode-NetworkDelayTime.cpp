#define INF 1000000
//Dijkstra

struct Graph {
    vector<unordered_map<int, int>> list;
    
    Graph(int n) {
        list = vector<unordered_map<int, int>>(n+1);
    }
    
    unordered_map<int, int> get_neighbours(int u) {
        return list[u];
    }
    
    void add_edge(int u, int v, int w) {
        list[u][v] = w;
    }
};

vector<int> shortest_path(Graph& g, int o) {
    
    vector<int> dists(g.list.size(), INF);
    
    dists[o] = 0;
    unordered_set<int> visited;
    vector<pair<int, int>> nodes;
    nodes.push_back({o, 0});
    push_heap(nodes.begin(), nodes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });
    
    while (!nodes.empty()) {
        auto w = nodes.front();
        pop_heap(nodes.begin(), nodes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        nodes.pop_back();
        
        for (auto v: g.get_neighbours(w.first)) {
            if (visited.count(v.first) > 0) continue;
            
            if (dists[w.first] + v.second < dists[v.first]) {
                dists[v.first] = dists[w.first] + v.second;
                nodes.push_back({v.first, dists[v.first]});
                push_heap(nodes.begin(), nodes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                    return a.second > b.second;
                });
            }
        }
        visited.insert(w.first);
    }
    return dists;
}


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        Graph g(N);
        
        for (int i = 0; i < times.size(); ++i) {
            g.add_edge(times[i][0], times[i][1], times[i][2]);
        }
        
        vector<int> dists = shortest_path(g, K);
        
        for (int i = 1; i < dists.size(); ++i) {
            if (dists[i] == INF) return -1;
        }
        
        int m = 0;
        for (int i = 1; i < dists.size(); ++i) m = max(m, dists[i]);
        
        return m;
    }
};
