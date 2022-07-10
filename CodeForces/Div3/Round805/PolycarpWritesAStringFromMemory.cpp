#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    string s; cin >> s;

    set<char> chars;
    int days = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (chars.size() < 3) {
        chars.insert(s[i]);
        continue;
      }
      if (chars.count(s[i]) > 0) {
        continue;
      }
      chars.clear();
      chars.insert(s[i]);
      ++days;
    }

    cout << days + (chars.size() > 0 ? 1 : 0) << endl;
  }
}
