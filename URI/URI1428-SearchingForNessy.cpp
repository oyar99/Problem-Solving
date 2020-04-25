#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, m; cin >> n >> m;

        int ans = ceil((n-2)/3.f) * ceil((m-2)/3.f);

        cout << ans << endl;
    }
}
