#define INF 10e7

#include <bits/stdc++.h>

using namespace std;

struct graph {
    unordered_map<int, unordered_map<int, int>> list;
    
    void add_edge(int u, int v, int w) {
        list[u][v] = w;
        list[v][u] = w;
    }
};

int prims(graph& g) {

    graph t;
    int w = 0;
    int u = 0;
    vector<pair<pair<int, int>, int>> edges;
    
    while (t.list.size() != g.list.size()) {
        for (const auto& v: g.list[u]) {
            if (t.list.count(v.first) > 0) continue;
            edges.push_back({{u, v.first}, v.second});
            push_heap(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
                return a.second > b.second;
            });
        }

        auto v = edges.front();
        pop_heap(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
                return a.second > b.second;
            });
        edges.pop_back();

        if (t.list.count(v.first.first) > 0 && t.list.count(v.first.second)) continue;

        u = v.first.second;
        t.add_edge(v.first.first, v.first.second, v.second);
        w += v.second;
    }

    return w;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (true) {
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        graph g;

        for (int i = 0; i < m; ++i) {
            int u, v, w; cin >> u >> v >> w;
            g.add_edge(u, v, w);
        }

        int w = prims(g);

        cout << w << endl;
        
    }

        
}
