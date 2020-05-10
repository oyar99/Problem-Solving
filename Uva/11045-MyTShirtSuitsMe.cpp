#include <bits/stdc++.h>

#define UNDEFINED -1348534
#define INF 1e7

using namespace std;

class graph {
    //adj[u][v] indicates an edge from u to v where adj[u][v].first is the flow going through that edge and adj[u][v].second is the capacity of the edge.
    vector<unordered_map<int, pair<int, int>>> adj;

    public:
        graph(int n) {
            adj = vector<unordered_map<int, pair<int, int>>>(n);
        }

        void add_edge(int u, int v, int c) {
            adj[u][v] = make_pair(0, c);
            adj[v][u] = make_pair(0, 0);
        }

        unordered_map<int, pair<int, int>> get_neighbours(int u) {
            return adj[u];
        }

        pair<int, int> get_edge(int u, int v) {
            return adj[u][v];
        }

        void augment_edge(int u, int v, int f) {
            adj[u][v].first += f;
            adj[v][u].first -= f; 
        }

        int get_size() {
            return adj.size();
        }
};

int bfs(graph& g) {
    queue<int> q;
    unordered_set<int> visited;
    vector<int> prev(g.get_size(), UNDEFINED);

    q.push(0);
    visited.insert(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == 1) break;

        for (auto& v: g.get_neighbours(u)) {
            if (visited.count(v.first) <= 0 && v.second.second - v.second.first > 0) {
                visited.insert(v.first);
                q.push(v.first);
                prev[v.first] = u;
            }
        }
    }

    if (prev[1] == UNDEFINED) return 0;

    int flow = INF;

    int u = 1;

    while (u != 0) {
        pair<int, int> edge = g.get_edge(prev[u], u);
        flow = min(flow, edge.second - edge.first);
        u = prev[u];
    }

    u = 1;

    while (u != 0) {
        g.augment_edge(prev[u], u, flow);
        u = prev[u];
    }

    return flow;
}

int max_bipartite_matching(graph& g) {
    int flow = 0;
    int f;

    do {
        f = bfs(g);
        flow += f;
    } while (f != 0);
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m; cin >> n >> m;

        graph g(6 + m  + 2);
        /*

        Vertices:
        
            adj[0] is the source
            adj[1] is the sink
            adj[2..7] are t-shirts
            adj[8..m+7] are volunteers

        */

        /*
            Map T-shirts sizes to integer ids
        */

        map<string, int> mp;

        mp["XXL"] = 2;
        mp["XL"] = 3;
        mp["L"] = 4;
        mp["M"] = 5;
        mp["S"] = 6;
        mp["XS"] = 7;

        //add edges between t-shirts and volunteers
        for (int i = 0; i < m; ++i) {
            string a, b; cin >> a >> b;

            g.add_edge(mp[a], 8+i, 1);
            g.add_edge(mp[b], 8+i, 1);
        }

        //add edges between source and t-shirts
        for (int i = 2; i < 8; ++i) {
            g.add_edge(0, i, n/6);
        }

        //add edges between volunteers and sink
        for (int i = 0; i < m; ++i) {
            g.add_edge(8+i, 1, 1);
        }

        int ans = max_bipartite_matching(g);

        if (ans == m) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}
