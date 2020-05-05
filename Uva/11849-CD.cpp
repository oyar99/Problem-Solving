#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (1) {
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> b(m);

        for (int i = 0; i < m; ++i) cin >> b[i];

        int count = 0;
        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (a[i] < b[j]) ++i;
            else if (a[i] > b[j]) ++j;
            else ++i,++j,++count;
        }

        cout << count << endl;
    }
}
