/*
    Uva Online Judge:
    12083-GuardianOfDecency

    First of all, we build a graph where each vertex is a student. We put an edge from u to v iff person u does not get along with person v.
    
    We want to find the size of a maximum independent set of a bipartite graph. 
    
    Note that the maximum independent set of a graph is the complement of a minimum vertex cover.

    Considering this, if we compute the number of vertices in a minimum vertex cover, we can derive the size of a maximum independent set.

    We should compute a maximum bipartite matching because the number of edges in it is equal to the number of vertices in a minumum vertex cover. (Konig's Theorem)

    Let MBP be the number of edges in the maximum bipartite matching. Then, the size of a maximum independent set is |V| - MBP

    The complexity is determined by the subroutine that computes the maximum bipartite matching. This is solved with Edmonds-Karp algorithm for maximum flow problem.
    (The maximum bipartite matching problem can be reduced to the maximum flow problem)

    Time Complexity: |V|*|E|^2

    The maximum independent set is NP-Hard for general graphs.

*/


#pragma GCC optimize("03")
#include <bits/stdc++.h>

#define UNDEFINED -1423423
#define INF 1e7

using namespace std;

struct person {
    int h;
    char sex;
    string music;
    string sport;
};

//This struct is used to represent an undirected graph
struct graph {
    vector<vector<int>> adj;

    graph(int n) {
        adj = vector<vector<int>>(n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int get_size() {
        return adj.size();
    }

    vector<int>& get_neighbours(int u) {
        return adj[u];
    }
};

//This struct is used to represent a directed graph which accepts flow through its edges
struct flow_graph {
    vector<unordered_map<int, pair<int, int>>> adj;

    void set_size(int n) {
        adj = vector<unordered_map<int, pair<int, int>>>(n);
    }

    void add_edge(int u, int v, int c) {
        if (adj[u].count(v) > 0) return;
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

int bfs(flow_graph& g) {
    queue<int> q;
    vector<bool> visited(g.get_size(), false);
    vector<int> prev(g.get_size(), UNDEFINED);

    q.push(g.get_size() - 2);
    visited[g.get_size() - 2] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == g.get_size() - 1) break;

        for (const auto&  v: g.get_neighbours(u)) {
            if (!visited[v.first] && v.second.second - v.second.first > 0) {
                visited[v.first] = true;
                q.push(v.first);
                prev[v.first] = u;
            }
        }
    }

    if (prev[g.get_size() - 1] == UNDEFINED) return 0;

    int flow = INF;

    int u = g.get_size() - 1;


    while (u != g.get_size() - 2) {
        pair<int, int> edge = g.get_edge(prev[u], u);
        flow = min(flow, edge.second - edge.first);
        u = prev[u];
    }

    u = g.get_size() - 1;

    while (u != g.get_size() - 2) {
        g.augment_edge(prev[u], u, flow);
        u = prev[u];
    }

    return flow;
} 

int max_bipartite_matching(flow_graph& g) {

    int flow = 0;
    int f; 

    do {
        f = bfs(g);
        flow += f;
    } while (f != 0);
    return flow;
}

void build_bipartite_flow_graph(graph& g, unordered_set<int>& X, unordered_set<int>& Y, flow_graph& h) {

    int n = g.get_size();

    h.set_size(n + 2);

    //adj[n] -> source
    //adj[n+1] -> sink
    for (int u: X) {
        h.add_edge(n, u, 1);
        for (int v: g.adj[u]) {
            h.add_edge(u, v, 1);
        }
    }
    for (int u: Y) h.add_edge(u, n+1, 1);
}

void get_bipartite(graph& g, unordered_set<int>& red, unordered_set<int>& blue) {

    vector<bool> visited(g.get_size(), false);

    for (int i = 0; i < g.get_size(); ++i) {
        if (visited[i]) continue;

        queue<int> q;
        q.push(i);
        visited[i] = true;
        red.insert(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            vector<int> &neigh = g.get_neighbours(u);

            for (int v: neigh) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);

                    if (red.count(u) > 0) {
                        blue.insert(v);
                    } else {
                        red.insert(v);
                    }
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        vector<person> v(n);

        for (int i = 0; i < n; ++i) {
            int h;
            char sex;
            string music, sport;
            cin >> h >> sex >> music >> sport;

            v[i] = {h, sex, music, sport};
        }

        graph g(n);

        auto compatible = [](person& a, person& b) {
            return abs(a.h - b.h) <= 40 && a.sex != b.sex && a.music == b.music && a.sport != b.sport;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (compatible(v[i], v[j])) {
                    g.add_edge(i, j);
                }
            }
        }

        unordered_set<int> X;
        unordered_set<int> Y;

        get_bipartite(g, X, Y);

        flow_graph h;
        build_bipartite_flow_graph(g, X, Y, h);

        int mbp = max_bipartite_matching(h);

        int mis = n - mbp;

        cout << mis << endl;
    }
}
