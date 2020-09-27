#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n, k; cin >> n >> k;

        int y = k/(n-1);

        if (k % (n-1) == 0) --y;

        cout << k + y << endl;

        
    }
}
