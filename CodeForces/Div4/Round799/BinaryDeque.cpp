#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    int n, s; cin >> n >> s;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin >> v[i];

    int l = 0;
    int r = 0;
    int cs = 0;
    int ml = -1;

    while (r < n) {
      while (cs <= s) {
        cs += v[r++];

        if (cs == s) {
          ml = max(ml, r - l);
        }

        if (r >= n) {
          break;
        }
      }

      while (cs > s) {
        cs -= v[l++];
      }
    }

    if (ml == -1) {
      cout << ml << endl;
      continue;
    }

    cout << n - ml << endl;
  }
}
