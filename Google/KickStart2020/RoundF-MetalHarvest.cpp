#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, K; cin >> N >> K;

        vector<pair<int, int>> I(N);

        for (int i = 0; i < N; ++i) {
            int l, r; cin >> l >> r;
            I[i] = {l , r};
        }

        sort(I.begin(), I.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        int r = K;
        int d = 1;

        for (int i = 0; i < N; ++i) {

            if (i > 0) r = max(r - (I[i].first - I[i-1].second), 0); 

            int dur = I[i].second - I[i].first;

            assert(dur > 0);
            
            if (r != 0 && r - dur >= 0) {
                r -= dur;
                assert(r >= 0);
            } else {
                dur -= r;

                assert(dur > 0);

                if (dur % K == 0) {
                    d += dur / K;
                } else {
                    d += (dur / K) + 1;
                }

                r = K - (dur % K);

                if (r >= K) r = 0;
            }
        }

        cout << "Case #" << t + 1 << ": " << d << endl;
    }
}
