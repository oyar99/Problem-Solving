/**
 * Calculates the critical path of a set of tasks. 
 * N is the number of events (Including the start and the end event)
 * M is the number of activities.
 * Each activity is described as u -> v with duration t. 
 * 
 * The start event is the node with index 0
 * The end event is the node with index N - 1
 * 
 * Time Complexity: O((V+E)^2)
 * 
 * */


#include <bits/stdc++.h>

#define INF 100000000

using namespace std;

struct edge {
    int time;
    int earliest_start;
    int earliest_end;
    int latest_start;
    int latest_end;
};

struct graph {

    vector<unordered_map<int,edge>> adj;

    graph(int n) {
        adj = vector<unordered_map<int, edge>>(n);
    }

    graph(const graph& g) {
        adj = vector<unordered_map<int, edge>>(g.adj);
    } 

    void add_edge(int u, int v, int t) {
        adj[u].insert({v, {
            t,
            0,
            t,
            0,
            INF
        }});
    }

    void add_edge(int u, int v, edge e) {
        adj[u].insert({v, e});
    }

    unordered_map<int, edge>& get_neighbours(int u) {
        return adj[u];
    }

};

void earliest(graph& g, int a, int b, int c) {
    edge& v = g.adj[a][b];
    edge& w = g.adj[b][c];
    w.earliest_start = max(w.earliest_start, v.earliest_end);
    w.earliest_end = w.earliest_start + w.time;
}

void latest(graph& g, int a, int b, int c) {
    edge& v = g.adj[a][b];
    edge& w = g.adj[b][c];
    w.latest_end = min(w.latest_end, v.latest_start);
    w.latest_start = w.latest_end - w.time;
}


void bfs(graph& g, int s, void (*f)(graph&, int, int, int)) {
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& v: g.get_neighbours(u)) {
            q.push(v.first);

            for (auto& w: g.get_neighbours(v.first)) {
                f(g, u, v.first, w.first);
            }
        }
    }
}

void handle_last_edges(graph& g) {
    for (auto& e: g.get_neighbours(g.adj.size() - 1)) {
        e.second.latest_start = e.second.earliest_start;
        e.second.latest_end = e.second.earliest_end;
    }
}

void reverse_graph(graph& g) {
    graph h(g.adj.size());
    for (int u = 0; u < g.adj.size(); ++u) {
        for (const auto& e: g.get_neighbours(u)) {
            h.add_edge(e.first, u, e.second);
        }
    }
    g = h;
}

void find_edges_on_critical_path(graph& g, vector<pair<int, int>>& out) {
    for (int u = 0; u < g.adj.size(); ++u) {
        for (const auto& e: g.get_neighbours(u)) {
            if (e.second.earliest_start == e.second.latest_start && e.second.earliest_end == e.second.latest_end) {
                out.push_back({u, e.first});
            }
        }
    }
}

void print_graph(graph& g) {
    for (int u = 0; u < g.adj.size(); ++u) {
        for (const auto& e: g.get_neighbours(u)) {
            cout << "Edge: " << u << " -> " << e.first << ": ";
            cout << "Earliest: [" << e.second.earliest_start << ", " << e.second.earliest_end << "] ";
            cout << "Latest: [" << e.second.latest_start << ", " << e.second.latest_end << "]" << endl;
        }
    }
    cout << endl;
    cout << "------------" << endl;
    cout << endl;
}

int main() {
    int n, m;

    cin >> n >> m;

    graph g(n);

    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;

        g.add_edge(u, v, t);
    }

    bfs(g, 0, earliest);
    reverse_graph(g);
    handle_last_edges(g);
    bfs(g, n - 1, latest);

    cout << "Graph: " << endl;
    cout << endl;
    reverse_graph(g);
    print_graph(g);

    vector<pair<int,int>> critical_path;
    find_edges_on_critical_path(g, critical_path);

    int time = 0;

    cout << "Critical Path: " << endl;
    cout << endl;
    for (const auto& edge: critical_path) {
        time += g.adj[edge.first][edge.second].time;
        cout << edge.first << " -> " << edge.second << endl;
    }

    cout << "------------" << endl;
    cout << endl;
    cout << "Critical time: " << endl;
    cout << endl;
    cout << time << endl; 
}
