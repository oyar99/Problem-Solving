#include <bits/stdc++.h>

using namespace std;

struct stone {
  int s;
  int e;
  int l;
};

int solve(vector<stone>& stones, int s, int i, vector<vector<int>>& memo) {
    if (i >= stones.size()) return 0;
    if (memo[s][i] != INT32_MIN) return memo[s][i];
    
    int a = stones[i].e - (stones[i].l * s) + solve(stones, s + stones[i].s, i + 1, memo);
    int b = solve(stones, s, i + 1, memo);
    memo[s][i] = max(a, b);
    return memo[s][i];
}

int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        vector<stone> stones(N);
        
        for (int i = 0; i < N; ++i) {
            int s, e, l; cin >> s >> e >> l;
            stones[i] = {s,e,l};
        }
        
        sort(stones.begin(), stones.end(), [](const stone& a, const stone& b) 
        {
          return a.s * b.l < b.s * a.l;  
        });

        vector<vector<int>> memo(10001, vector<int>(100, INT32_MIN));
        int ans = solve(stones, 0, 0, memo);

        cout << ans << endl;
    }
}