#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    string w; cin >> w;
    int p; cin >> p;

    vector<int> v(26);

    for (int i = 0; i < w.size(); ++i) {
      v[w[i] - 'a'] += 1;
    }

    int price = 0;
    for (int i = 0; i < 26; ++i) {
      price += v[i] * (i + 1);
    }

    vector<int> vv(26);

    for (int i = 25; i >= 0; --i) {
      if (price <= p) {
        break;
      }

      if (price - v[i] * (i + 1) > p) {
        vv[i] = v[i];
        price -= v[i] * (i + 1);
        assert(price > p);
        continue;
      }

      int l = 0;
      int r = v[i];

      while (l < r) {
        int m = (l + r) >> 1;

        if (price - m * (i + 1) > p) {
          l = m + 1;
        } else {
          r = m;
        }
      }

      vv[i] = l;
      price -= l * (i + 1);
      assert(price <= p);      
    }

    string ans;

    for (int i = 0; i < w.size(); ++i) {
      if (vv[w[i] - 'a'] > 0) {
        vv[w[i] - 'a']--;
        continue;
      }
      ans.push_back(w[i]);
    }

    for (int i = 0; i < 26; ++i) {
      assert(vv[i] == 0);
    }

    cout << ans << endl;
  }
}
