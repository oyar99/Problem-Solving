#include <bits/stdc++.h>

#define UNDEFINED -1348534
#define INF 1e7

using namespace std;

struct edge {
    int id;
    int u;
    int v;
    int capacity;
    int flow;
};

class graph {
    vector<vector<edge>> adj;
    int idx = 0;

    public:
        graph(int n) {
            adj = vector<vector<edge>>(n+1);
        } 

        void add_edge(int u, int v, int c) {
            adj[u].push_back({idx, u, v, c, 0});
            adj[v].push_back({idx, v, u, c, 0});
            ++idx;
        }

        vector<edge> get_edges(int u) {
            return adj[u];
        }

        void augment_edge(edge& e, int f) {
            
            for (edge& e1: adj[e.u]) {
                if (e1.id == e.id) {
                    e1.flow += f;
                    break;
                }
            }

            for (edge& e2: adj[e.v]) {
                if (e2.id == e.id) {
                    e2.flow -= f;
                    break;
                }
            }
        }

        int get_size() {
            return adj.size();
        }
};

int bfs(graph& g, int s, int t) {
    queue<int> q;
    unordered_set<int> visited;
    vector<edge> prev(g.get_size(), {UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED});

    q.push(s);
    visited.insert(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();


        if (u == t) break;

        for (edge& e: g.get_edges(u)) {
            if (e.capacity - e.flow > 0 && visited.count(e.v) <= 0) {
                visited.insert(e.v);
                q.push(e.v);
                prev[e.v] = e;
            } 
        }
    }

    if (prev[t].id == UNDEFINED) return 0;

    int flow = INF;

    int u = t;

    while (u != s) {
        flow = min(flow, prev[u].capacity - prev[u].flow);
        u = prev[u].u;
    }

    u = t;

    while (u != s) {
        g.augment_edge(prev[u], flow);
        u = prev[u].u;
    } 

    return flow;
}

int max_flow(graph& g, int s, int t) {
    int flow = 0;
    int f;
    do {
        f = bfs(g, s, t);
        flow += f;
    } while (f != 0);
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;

    while (1) {
        int n; cin >> n;

        if (n == 0) break;

        int s, t; cin >> s >> t;

        int m; cin >> m;


        graph g(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c; cin >> u >> v >> c;

            g.add_edge(u, v, c);
        }

        int ans = max_flow(g, s, t);

        cout << "Network " << T++ << endl;
        cout << "The bandwidth is " << ans << "." << endl;
        cout << endl;

    }
}
