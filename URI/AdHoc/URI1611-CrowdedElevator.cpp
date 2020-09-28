#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, c, m; cin >> n >> c >> m;

        vector<int> P(m);

        for (int i = 0; i < m; ++i) cin >> P[i];

        sort(P.begin(), P.end(), greater<int>());

        int e = 0;

        for (int i = 0;i < m; i+=c ) {
            e += P[i] * 2;
        }

        cout << e << endl;
    }
}
