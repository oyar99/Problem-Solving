#include <bits/stdc++.h>

using namespace std;


int main () {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, k; cin >> n >> k;

        vector<int> P(n);

        for (int i = 0; i < n; ++i) cin >> P[i];

        sort(P.begin(), P.end());

        P.push_back(k);

        vector<int> D;

        double ans = 0;

        for (int i = 0; i < n + 1; ++i) {
            int dif;

            if (i == n) {
                dif = P[i] - P[i-1];
            } else if (i == 0) {
                dif = P[i] - 1;
            } else {
                dif = ceil((P[i] - P[i-1] - 1)/2.f);
            }

            D.push_back(dif);

            // best ans might be to choose two numbers in the same interval
            if (i != n && i != 0) {
                ans = max(ans, ((double)P[i] - P[i-1] - 1) / k);
            }
        }

        sort(D.begin(), D.end(), greater<int>());

        int w = D[0] + D[1];

        ans = max(ans, (double)(w) / k);

        cout << setprecision(12) << "Case #" << (t+1) << ": " << ans << endl;
    } 
}
