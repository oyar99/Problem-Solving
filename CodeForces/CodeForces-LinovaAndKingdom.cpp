#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Graph {
    unordered_map<int, unordered_set<int>> list;

    void add_edge(int u, int v) {
        list[u].insert(v);
        list[v].insert(u);
    }
};

int dfs(Graph& g, int u, unordered_set<int>& visited, vector<int>& succ) {
    for (int v: g.list[u]) {
        if (visited.count(v) <= 0) {
            visited.insert(v);
            succ[u] += 1 + dfs(g, v, visited, succ);
        }
    }
    return succ[u];
}

void dfs(Graph& g, unordered_map<int, int>& dists) {
    stack<int> s;
    unordered_set<int> visited;
    s.push(1);
    visited.insert(1);
    dists[1] = 0;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        
        for (int v: g.list[u]) {
            if (visited.count(v) <= 0) {
                visited.insert(v);
                s.push(v);
                dists[v] = dists[u] + 1;
            }
        }
    }
}

ll dfs(Graph& g, vector<bool>& marked) {

    //above(i) is the number of non-marked nodes in the path from 1 to i  inclusive.
    vector<int> above(g.list.size() + 1);
    above[1] = 1;

    unordered_set<int> visited;
    stack<int> s;
    s.push(1);
    visited.insert(1);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        for (int v: g.list[u]) {

            if (visited.count(v) <= 0) { 
                s.push(v);
                visited.insert(v);
                if (marked[v]) above[v] = above[u];
                else above[v] = above[u] + 1;
            }
        }

    }

    ll sum = 0;

    for (int u = 1; u < g.list.size() + 1; ++u) {
        if (marked[u]) sum += above[u];
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;

    Graph g;

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g.add_edge(u,v);
    }

    vector<int> succ(n+1, 0);
    unordered_set<int> visited;
    visited.insert(1);
    dfs(g, 1, visited, succ);

    unordered_map<int, int> dists;
    dfs(g, dists);

    vector<pair<int, int>> vertices;

    for (auto& e: dists) vertices.push_back({e.first, dists[e.first] - succ[e.first]});

    sort(vertices.begin(), vertices.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    vector<bool> marked(n+1);

    for (int i = 0; i < k; ++i) marked[vertices[i].first] = true;

    cout << dfs(g,marked) << endl;
    
}
