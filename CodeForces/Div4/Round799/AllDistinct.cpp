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

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    set<int> s;

    for (int x : v) {
      s.insert(x);
    }

    int dups = n - s.size();

    if (dups & 1) {
      cout << s.size() - 1 << endl;
    } else {
      cout << s.size() << endl;
    }
  }
}
