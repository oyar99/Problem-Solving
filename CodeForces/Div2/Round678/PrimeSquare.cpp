#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        int A [n][n];

        memset(A, 0, sizeof(A));

        for (int i = 0; i < n; ++i) {
            A[i][n - i - 1] = 4;
            if (n - i - 2 >= 0) A[i][n - i - 2] = 1;
            else A[i][n-1] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
}