#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    int a, b, c, d; cin >> a >> b >> c >> d;

    int ans = 0;

    if (b > a) ++ans;
    if (c > a) ++ans;
    if (d > a) ++ans;

    cout << ans << endl;
  }
}
