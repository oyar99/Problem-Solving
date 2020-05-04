#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        string s; cin >> s;

        s += s;

        int i = 0;
        int ans = 0;

        while (i < (s.size() >> 1)) {
            ans = i;

            int j = i + 1, k = i;

            while (j < s.size() && s[k] <= s[j]) {
                if (s[k] < s[j]) {
                    k = i;
                } else {
                    ++k;
                }
                ++j;
            }

            while (i <= k) i += j - k;
        }

        cout << ans + 1 << endl;
    }
}
