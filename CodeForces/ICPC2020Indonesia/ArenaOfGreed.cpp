#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        ll N; cin >> N;

        ll c = 0;

        while (N > 0) {
            if (N & 1) {
                --N;
                ++c;
            } else {
                if (N == 4) {
                    N = 2;
                    c += 2;
                }
                else if ((N/2 & 1)) {
                    N /= 2;
                    c += N;
                } else {
                    --N;
                    ++c;
                }
            }

            if (N & 1) {
                --N;
            } else {
                if (N == 4) {
                    N = 2;
                }
                else if ((N/2 & 1)) {
                    N /= 2;
                } else {
                    --N;
                }
            }
        }

        cout << c << endl;
    }
}
