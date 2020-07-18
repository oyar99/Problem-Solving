#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) cin >> v[i];

        int r = 0;

        for (int i = n - 1; i >= 0; --i) {
            r = i;
            if (i > 0 && v[i] > v[i-1]) {
                break;
            }
        }

        for (int i = r - 1; i >= 0; --i) {
            r = i;
            if (i > 0 && v[i] < v[i-1]) {
                break;
            }
        }

        cout << r << endl;
    }
}
