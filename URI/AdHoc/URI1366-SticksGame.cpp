#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (1) {

        cin >> n;

        if (n == 0) break;

        int count = 0;
        int left_over = 0;
        for (int i = 0; i < n; ++i) {
            int q, v; cin >> q >> v;

            count += (v >> 2);

            if (v % 4 >= 2) left_over += 2;
        }

        count += (left_over >> 2);

        cout << count << endl;
    }
}
