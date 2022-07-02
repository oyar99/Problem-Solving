#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    int n; cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin >> v[i];

    set<vector<int>> s;
    vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int x : digits) {
      for (int y: digits) {
        for (int z: digits) {
          if ((x + y + z) % 10 != 3) continue;

          vector<int> cand = { x, y, z };
          sort(cand.begin(), cand.end());

          s.insert(cand);
        }
      }
    }

    vector<int> count(10);

    for (int x : v) {
      count[x % 10]++;
    }

    bool pos = false;

    for (const vector<int>& op : s) {
      bool ok = true;

      vector<int> count_op(10);

      for (int x: op) {
        count_op[x]++;
      }

      for (int i = 0; i < 10; ++i) {
        if (count_op[i] > count[i]) {
          ok = false;
          break;
        }
      }

      if (ok) {
        pos = true;
        break;
      }
    }

    cout << (pos ? "YES" : "NO") << endl;
  }
}
