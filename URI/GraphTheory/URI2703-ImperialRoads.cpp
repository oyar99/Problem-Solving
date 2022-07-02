#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

const int MAX_LOG = 2e5+1;
int logs[MAX_LOG];

int mst(vector<unordered_map<int, int>>& adj, vector<pair<pair<int, int>, int>>& edges, vector<unordered_map<int, int>>& adj_t) {
  int w = 0;

  sort(edges.begin(), edges.end(), [](const pair<pair<int, int>, int>& uv, const pair<pair<int, int>, int>& vw) {
    return uv.second < vw.second;
  });

  vector<int> disjoint_set(adj.size());
  vector<int> rank(adj.size());

  for (int i = 1; i < adj.size(); ++i) {
    disjoint_set[i] = i;
  }

  function<int(int)> find_set = [&](int u) {
    if (disjoint_set[u] == u) {
      return u;
    }

    disjoint_set[u] = find_set(disjoint_set[u]);
    return disjoint_set[u];
  };

  function<bool(int, int)> union_set = [&](int u, int v) {
    int uu = find_set(u);
    int vv = find_set(v);

    if (uu == vv) {
      return false;
    }

    if (rank[uu] < rank[vv]) {
      disjoint_set[uu] = vv;
    } else if (rank[uu] > rank[vv]) {
      disjoint_set[vv] = uu;
    } else {
      disjoint_set[vv] = uu;
      ++rank[uu];
    }

    return true;
  };

  for (int i = 0; i < edges.size(); ++i) {
    int u = edges[i].first.first;
    int v = edges[i].first.second;

    if (!union_set(u, v)) continue;

    adj_t[u][v] = adj_t[v][u] = adj[u][v];
    w += adj[u][v];
  }

  return w;
}

void et(vector<unordered_map<int, int>>& adj, vector<int>& tour_out, vector<int>& h_out, vector<vector<int>>& p, int sz) {
  vector<int> s;
  s.reserve(adj.size());
  vector<bool> visited(adj.size(), false);
  vector<int> h(adj.size());

  s.push_back(1);
  h[1] = 1;

  while (!s.empty()) {
    int u = s.back();
    s.pop_back();

    tour_out.push_back(u);
    h_out.push_back(h[u]);

    if (!visited[u]) {
      visited[u] = true;

      for (int i = 1; i < sz; ++i) {
        p[i][u] = p[i-1][p[i-1][u]];
      }

      for (const pair<int, int>& w : adj[u]) {
        int v = w.first;
        int c = w.second;

        if (visited[v]) continue;

        s.push_back(u);
        s.push_back(v);

        h[v] = h[u] + 1;
        p[0][v] = u;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, R;
  cin >> N >> R;

  vector<unordered_map<int, int>> adj(N + 1);
  vector<pair<pair<int, int>, int>> edges(R);

  for (int i = 0; i < R; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u][v] = adj[v][u] = c;
    edges[i] = { make_pair(u, v), c };
  }

  logs[1] = 0;
  for (int i = 2; i < MAX_LOG; ++i) {
    logs[i] = logs[i / 2] + 1;
  }

  vector<unordered_map<int, int>> adj_t(N + 1);
  int mst_ans = mst(adj, edges, adj_t);

  vector<int> tour;
  tour.reserve(2*N);
  vector<int> h;
  h.reserve(2*N);
  vector<vector<int>> p(logs[N + 1] + 1, vector<int>(adj.size()));
  et(adj_t, tour, h, p, logs[N + 1] + 1);

  vector<int> fo(adj_t.size(), -1);
  for (int i = 0; i < tour.size(); ++i) {
    if (fo[tour[i]] != -1) continue;
    fo[tour[i]] = i;
  }

  int ts = tour.size();
  auto min_by_h = [&](int i, int j) {
    return h[i] < h[j] ? i : j;
  };

  vector<vector<int>> st(logs[ts] + 1, vector<int>(ts));

  for (int i = 0; i < ts; ++i) {
    st[0][i] = i;
  }

  for (int i = 1; i < logs[ts] + 1; ++i) {
    for (int j = 0; j + (1 << i) <= ts; ++j) {
      st[i][j] = min_by_h(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }

  vector<vector<int>> st_act(logs[N + 1] + 1, vector<int>(N + 1));

  for (int i = 1; i <= N; ++i) {
    st_act[0][i] = adj_t[i][p[0][i]];
  }

  for (int i = 1; i < logs[N + 1] + 1; ++i) {
    for (int j = 1; j < N + 1; ++j) {
      st_act[i][j] = max(st_act[i - 1][j], st_act[i - 1][p[i - 1][j]]);
    }
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int u, v;
    cin >> u >> v;

    if (adj_t[u][v] > 0) {
      cout << mst_ans << endl;
      continue;
    }
    
    int iu = fo[u];
    int iv = fo[v];

    if (iu > iv) {
      swap(iu, iv);
    }

    int lca = tour[min_by_h(st[logs[iv - iu]][iu], st[logs[iv - iu]][iv - (1 << logs[iv - iu])])];

    int max_e = 0;
    int uu = u;
    int vv = v;

    while (h[fo[uu]] != h[fo[lca]]) {
      max_e = max(max_e, st_act[logs[h[fo[uu]] - h[fo[lca]]]][uu]);
      uu = p[logs[h[fo[uu]] - h[fo[lca]]]][uu];
    }

    while (h[fo[vv]] != h[fo[lca]]) {
      max_e = max(max_e, st_act[logs[h[fo[vv]] - h[fo[lca]]]][vv]);
      vv = p[logs[h[fo[vv]] - h[fo[lca]]]][vv];
    }

    cout << mst_ans - max_e + adj[u][v] << endl;
  }
}
