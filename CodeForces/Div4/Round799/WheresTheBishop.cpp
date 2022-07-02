#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;

  for (int t = 0; t < T; ++t) {
    vector<vector<bool>> board(8, vector<bool>(8, false));

    for (int i = 0; i < 8; ++i) {
      string s; cin >> s;

      for (int j = 0; j < 8; ++j) {
        board[i][j] = s[j] == '#';
      }
    }

    auto find = [&] {
      for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
          if (board[i+1][j+1]) {
            if (board[i][j]) {
              ++i; ++j;
              while (i < 7 && j < 7) {
                if (board[i-1][j+1]) {
                  return make_pair(i, j);
                }
                ++i; ++j;
              }
              assert(false);
            }
            ++i; ++j;
            while (i < 7 && j > 0) {
              if (board[i-1][j-1]) {
                return make_pair(i, j);
              }
              ++i; --j;
            }
            assert(false);
          }
        }
      }
      return make_pair(-1, -1);
    };

    auto ans = find();

    if (ans.first == -1 && ans.second == -1) {
      for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
          swap(board[i][j], board[j][i]);
        }
      }

      for (int i = 0, j = 7; i < j; ++i, --j) {
        for (int k = 0; j < 8; ++k) {
          swap(board[i][k], board[j][k]);
        }
      }

      ans = find();
      int tmp = ans.first;
      ans.first = ans.second;
      ans.second = 8 - tmp + 1;
    }

    cout << ans.first + 1 << " " << ans.second + 1 << endl;
  }
}
