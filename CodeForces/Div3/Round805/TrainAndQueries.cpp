#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    int n, k; cin >> n >> k;

    unordered_map<long long, int> f;
    unordered_map<long long, int> l;

    for (int i = 0; i < n; ++i) {
      long long val;
      cin >> val;
      if (f.count(val) <= 0) {
        f.insert( {val, i });
        l.insert( {val, i });
      } else {
        l[val] = i;
      }
    }

    for (int i = 0; i < k; ++i) {
      long long u, v; cin >> u >> v;

      if (f.count(u) > 0 && f[u] < l[v]) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
