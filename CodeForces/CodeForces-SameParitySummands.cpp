#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, k; cin >> n >> k;

        if (n & 1 && !(k&1)) {
            cout << "NO" << endl;
            continue;
        }

        if (k > n) {
            cout << "NO" << endl;
            continue;
        }

        //try evens

        int x = 2 * (k - 1);

        if (x < n) {

            if (!((n - x) & 1)) {
                cout << "YES" << endl;

                for (int i = 0; i < k - 1; ++i) cout << 2 << " ";
                cout << n - x << endl;
                continue;
            }

        }

        //try odds

        int y = (k - 1);

        if (y < n) {

            if ((n - y) & 1) {
                cout << "YES" << endl;

                for (int i = 0; i < k - 1; ++i) cout << 1 << " ";
                cout << n - y << endl;
                continue;
            }

        }

        cout << "NO" << endl;
    }
}
