#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        for (int i = n * 2, j = 0; j < n; i+=2, ++j) {
            cout << i << " ";
        }
        cout << endl;
    }
}
