#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    long long m; cin >> m;
    string s = to_string(m);

    cout << m - (long long)pow(10, s.size() - 1) << endl;
  }
}
