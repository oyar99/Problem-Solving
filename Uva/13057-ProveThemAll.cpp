#include <bits/stdc++.h>

using namespace std;

struct graph {
    unordered_map<int, unordered_set<int>> adj;

    void add_edge(int u, int v) {
        adj[u].insert(v);
    }

    void del_vertex(int u) {
        adj.erase(u);
    }
};

int scc(graph& g, int n) {
    
    unordered_map<int, int> component;
    int count = 0;
    int idx = 0;
    stack<int> s;
    unordered_set<int> on_stack;
    unordered_map<int, int> index;
    unordered_map<int, int> low;

    function<void (int)> connect = [&] (int u) {
        index[u] = idx;
        low[u] =  idx;

        ++idx;

        s.push(u);
        on_stack.insert(u);

        for (int v: g.adj[u]) {
            if (index.count(v) <= 0) {
                connect(v);
                low[u] = min(low[u], low[v]);
            } else if (on_stack.count(v) > 0) {
                low[u] = min(low[u], index[v]);
            }
        }

        if (low[u] == index[u]) {
            int v;
            do {
                v = s.top();
                s.pop();
                on_stack.erase(v);
                component[v] = count;
            } while (u != v);
            ++count;
        }
    };

    for (int u = 1; u <= n; ++u) {
        if (g.adj.count(u) <= 0) continue;

        if (index.count(u) <= 0) {
            connect(u);
        }
    }

    graph t;

    for (int i = 1; i <= n; ++i) {
        if (g.adj.count(i) <= 0) continue;

        for (int j: g.adj[i]) {
            int u = component[i];
            int v = component[j];

            if (u != v) {
                t.add_edge(u, v);
            }
        }
    }

    unordered_map<int, int> deg;

    for (int i = 0; i < count; ++i) {
        deg[i] = 0;
        for (int j: t.adj[i]) {
            deg[j]++;
        }
    }
    
    int d = 0;

    for (int i = 0; i < count; ++i) {
        if (deg[i] == 0) ++d;
    }
    
    return d;
}

int dfs(graph& g, int n) {
    vector<int> deg(n+1);

    for (int i = 1; i <= n; ++i) {
        for (int j : g.adj[i]) {
            deg[j]++;
        }  
    }

    vector<pair<int, int>> v;

    for (int i = 1; i <= n; ++i) v.push_back({i, deg[i]});

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    unordered_set<int> proved;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        pair<int, int> u = v[i];

        if (u.second > 0) {
            
            for (int v: proved) g.del_vertex(v);

            ans += scc(g, n);
            break;
        }

        if (proved.count(u.first) > 0) continue;

        ++ans;

        stack<int> s;
        s.push(u.first);

        while (!s.empty()) {
            int v = s.top();
            s.pop();

            if (proved.count(v) <= 0) {
                proved.insert(v);

                for (int w: g.adj[v]) {
                    s.push(w);
                }   
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 1; t<= T; ++t) {

        int n, m; cin >> n >> m;

        graph g;

        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            g.add_edge(u , v);
        }

        int ans = dfs(g, n);

        cout << "Case " << t << ": " << ans << endl;
        
    }
}
