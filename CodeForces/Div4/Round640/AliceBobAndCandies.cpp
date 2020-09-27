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

        int moves = 0;
        int a = 0;
        int b = 0;


        int l = 0;
        int r = n - 1;

        bool turn = true;

        int k = 0;

        for (;l <= r;) {
            ++moves;
            if (turn) {
                int s = 0;
                while (s <= k && l <= r) {
                    s += v[l++];
                }
                a += s;
                if (s <= k) {
                    while (l <= r) {
                        a += v[l++];
                    }
                    break;
                }
                k = s;
                

                
            } else {
                int s = 0;
                while (s <= k && l <= r) {
                    s += v[r--];
                }
                b += s;
                if (s <= k) {
                    while (l <= r) {
                        b += v[r--];
                    }
                    break;
                }
                k = s;
                
            }
            turn = !turn;
        }

        cout << moves << " " << a << " " << b << endl;

    }
}
