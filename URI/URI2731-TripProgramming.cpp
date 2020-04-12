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

pair<vector<int>, int> dijkstra(graph& g, int d) {

    vector<int> dp(g.list.size() + 1, INF);
    dp[1] = 0;

    vector<int> from(g.list.size() + 1, -1);

    unordered_set<int> visited;

    vector<pair<int, int>> pq;

    pq.push_back({1, 0});
    push_heap(pq.begin(), pq.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    while (!pq.empty()) {
        auto u = pq.front();
        pop_heap(pq.begin(), pq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        pq.pop_back();
        
        for (auto& v:g.list[u.first]) {
            if (visited.count(v.first) > 0) continue;
            
            if (v.second + dp[u.first] < dp[v.first]) {
                dp[v.first] = dp[u.first] + v.second;
                from[v.first] = u.first;
                pq.push_back({v.first, dp[v.first]});
                push_heap(pq.begin(), pq.end(), [](const auto& a, const auto& b) {
                    return a.second > b.second;
                });
            }
        }

        visited.insert(u.first);
    }

    vector<int> path;
    path.push_back(d);
    int u = from[d];

    while (u != 1) {
        path.push_back(u);
        u = from[u];
    }
    path.push_back(1);
    return {path, dp[d]};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, e;

    while (true) {
        cin >> c >> e;

        if (c == 0 && e == 0) break;

        graph g;

        for (int i = 0; i < e; ++i) {
            int u, v, w; cin >> u >> v >> w;
            g.add_edge(u, v, w);
        }

        int d; cin >> d;

        pair<vector<int>, int> info = dijkstra(g, d);

        string msg;

        if (info.second > 120) msg = "It will be " + to_string((info.second - 120)) + " minutes late. Travel time - " + to_string((info.second)) + " - best way - ";
        else msg = "Will not be late. Travel time - " + to_string((info.second)) + " - best way - ";

        string way = "";

        for (int i = 0; i < info.first.size() - 1; ++i) way += to_string(info.first[i]) + " ";

        way += to_string(info.first.back());

        msg += way;

        cout << msg << endl;
        
    }

        
}
