#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> T(n);
    vector<int> S(n);

    for (int i = 0; i < n; ++i) cin >> T[i];

    for (int i = 0; i < n;++i) cin >> S[i];

    vector<int> P(n);

    for (int i = 0; i < n; ++i) P[i] = T[i] -  S[i];

    sort(P.begin(), P.end());

    long long count = 0;
    long long i = 0;
    for (; i < n; ++i) {
        if (P[i] > 0) break;
        upper_bound(P.begin(), P.end(), abs(P[i]));
        count += distance(upper_bound(P.begin(), P.end(), abs(P[i])), P.end());
    }

    count += (long long)(n-i) * (long long)(n-i-1) >> 1;

    cout << count << endl;
}