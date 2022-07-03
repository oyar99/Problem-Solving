#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    int n; cin >> n;

    vector<pair<double, double>> points(n);

    for (int i = 0; i < n; ++i) {
      double x, y; cin >> x >> y;
      points[i] = make_pair(x, y);
    }

    vector<unordered_map<int, double>> adj(n);

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        adj[i][j] = adj[j][i] = abs(points[i].first - points[j].first) * abs(points[i].first - points[j].first) 
          + abs(points[i].second - points[j].second) * abs(points[i].second - points[j].second);
      }
    }

    auto prim = [&] {
      double w = 0;

      vector<bool> vertices(n, false);
      int count = 1;
      int u = 0;
      vertices[u] = true;

      auto cmp = [](const pair<pair<int, int>, double>& uv, const pair<pair<int, int>, double>& vw) {
        return uv.second > vw.second;
      };

      priority_queue<pair<pair<int, int>, double>, vector<pair<pair<int, int>, double>>, decltype(cmp)> pq(cmp);

      while (count < n) {
        for (const pair<int, double>& edge : adj[u]) {
          if (!vertices[edge.first]) {
            pq.push({ make_pair(u, edge.first), edge.second });
          }
        }

        while (vertices[pq.top().first.second]) {
          pq.pop();
        }

        pair<pair<int, int>, double> edge = pq.top();
        pq.pop();

        w += sqrt(edge.second);
        vertices[edge.first.second] = true;
        ++count;
        u = edge.first.second;
      }

      return w;
    };

    double ans = prim();

    ans /= 100.f;
    printf("%.2f\n", ans);
  }
}