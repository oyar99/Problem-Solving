#include <bits/stdc++.h>

using namespace std;

struct apple {
    int x;
    int y;
    int t;
};

int memo[21][21][2001];

//This dynamic programming problem has a runtime complexity of O(nmK^2)

int get_max(unordered_map<int, vector<pair<int, int>>>&  A, int n, int m, int i, int j, int t) {
    if (i <= 0 || i > n || j <= 0 || j > m) return 0;

    if (memo[i][j][t] != -1) return memo[i][j][t];

    if (t >= 2001) return 0;

    vector<pair<int, int>> vec = A[t];

    int count = 0;
    for (int k = 0; k < vec.size(); ++k) {
        if (vec[k].first == i && vec[k].second == j) {
            count+=1;
            break;
        }
    }

    int v = count + max({get_max(A, n, m, i+1, j, t+1), get_max(A, n, m, i-1, j, t+1),
                        get_max(A, n, m, i, j+1, t+1), get_max(A, n, m, i, j-1, t+1),
                        get_max(A, n, m, i-1, j-1, t+1), get_max(A, n, m, i+1, j-1, t+1),
                        get_max(A, n, m, i-1, j+1, t+1), get_max(A, n, m, i+1,j+1, t+1), 
                        get_max(A, n, m, i, j, t+1)});

    memo[i][j][t] = v;

    return v;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n, m, k;
        cin >> n >> m >> k;

        if (n == 0 && m == 0 && k == 0) break;

        memset(memo, -1, sizeof(memo));
        
        unordered_map<int, vector<pair<int, int>>> A;

        for (int i = 0; i < k; ++i) {
            int x, y, t; cin >> x >> y >> t;
            
            A[t].push_back({x, y});
        }

        int i_0, j_0; cin >> i_0 >> j_0;


        int ans = get_max(A, n, m, i_0, j_0, 0);

        cout << ans << endl;

    }
}
