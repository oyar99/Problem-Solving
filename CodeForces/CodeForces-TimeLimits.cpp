#include <bits/stdc++.h>

#define INF 10e8

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s; cin >> n >> s;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) cin >> v[i];

    int m = 0;

    for (int i = 0; i < n; ++i) m = max(m, v[i]);

    m *= s;

    if (m % 1000 == 0) {
        cout << m/1000 << endl;
        return 0;
    }

    cout << m/1000 + 1 << endl;
}
