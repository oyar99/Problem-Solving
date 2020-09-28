#include <bits/stdc++.h>
using namespace std;

class Compare {
    public:
    bool operator() (const pair<int, double>& a, const pair<int, double>& b) {
        return a.second < b.second;
    }
};

class Graph {
    private:
        unordered_map<int, unordered_map<int, int>> list;
    public:
        void add_vertex(int u) {
            list[u] = unordered_map<int, int>();
        }

        void add_edge(int u, int v, int p) {
            list[u][v] = p;
            list[v][u] = p;
        }

        int edge(int u, int v) {
            return list[u][v];
        }

        unordered_map<int, int> get_neighbours(int u) {
            return list[u];
        }

        unordered_map<int, unordered_map<int, int>> get_vertices() {
            return list;
        }

        int vertices() {
            return list.size();
        }

};

vector<int> dijkstra(Graph& g, int s, int d) {
    vector<double> table(g.vertices() + 1, 1);
    vector<bool> not_set(g.vertices() + 1, false);
    vector<int> from(g.vertices() + 1, -1);
    unordered_set<int> visited;
    priority_queue<pair<int, double>, vector<pair<int, double>> ,Compare> q;

    int u = s;
    q.push({u, 0});
    while (!q.empty()) {
        auto w = q.top();
        q.pop();
        for (auto v: g.get_neighbours(w.first)) {
            if (visited.count(v.first) > 0) continue;

            double p = (double)v.second / 100;
            if (p * table[w.first] > table[v.first] || !not_set[v.first]) {
                not_set[v.first] = true;
                table[v.first] = p * table[w.first];
                from[v.first] = w.first;
                q.push({v.first, p * table[w.first]});
            }
        }
        visited.insert(w.first);
    }
    vector<int> path;
    path.push_back(d);
    int w = from[d];
    while (w != s) {
        path.push_back(w);
        w = from[w];
    }
    path.push_back(s);
    return path;
}

int main() {
    int N, M;
    cin >> N;
    while (N != 0) {
        cin >> M;
        Graph city;

        for (int i = 1; i <= N;++i) {
            city.add_vertex(i);
        }

        for (int i = 0; i < M;++i) {
            int a, b, p; cin >> a >> b >> p;
            city.add_edge(a, b, p);
        }
        vector<int> path = dijkstra(city, 1, N);
        double p = 1;
        for (int i = 0; i < path.size() - 1;++i) {
            p *= (double)city.edge(path[i], path[i+1])/ 100;
        }
        p = (p * 100);
        printf("%.6f percent\n", p);
        cin >> N;
    }
}
