#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            vector<int> r(n);
            for (int j = 0; j < n; ++j) {
                cin >> r[j];
            }
            A[i] = r;
        }

        int k = 0;

        for (int i = 0; i < n; ++i) k+=A[i][i];

        int r = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> s;
            for (int j = 0; j < n; ++j) s.insert(A[i][j]);

            if (s.size() < n) ++r;
        }

        int c = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> s;
            for (int j = 0; j < n; ++j) s.insert(A[j][i]);

            if (s.size() < n) ++c;
        }

        cout << "Case #" << t << ": " << k << " " << r << " " << c << endl; 
    }
}
