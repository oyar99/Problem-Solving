#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, k; cin >> n >> k;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) cin >> v[i];

        sort(v.begin(), v.end(), greater<int>());

        int ops = 0;

        for (int i = 0; i < n - 1; ++i) ops += (k - v[i]) / v[n-1];

        cout << ops << endl;
        
    }
}