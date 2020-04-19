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

        int count = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (v[i] > v[i-1] && v[i] > v[i+1]) ++count;
        }

        cout << "Case #" << t+1 << ": " << count << endl;
    }
}
