#include <bits/stdc++.h>

#define INF 10e8

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        vector<int> v(n);

        for (int i = 1; i <= n; ++i) {
            v[i-1] = (1 << i);
        }

        int a = v[n-1];

        for (int i = 0; i < (n >> 1) - 1; ++i) a += v[i];

        int b = 0;

        for (int i = (n >> 1) - 1; i < n - 1; ++i) b += v[i];

        cout << a - b << endl;
    }
}
