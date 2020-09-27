#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; ++i) cin >> v[i];

        unordered_set<int> s;

        for (int i = 0; i < n; ++i) s.insert(v[i]);

        cout << n - (n - s.size())  << endl;
    }
}