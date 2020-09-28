#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        int X; cin >> X;

        vector<int> A(N);

        for (int i = 0; i < N; ++i) cin >> A[i];

        vector<pair<int, int>> Y(N);

        for (int i = 0; i < N; ++i) Y[i] = {i, ceil((double)A[i]/X)};

        stable_sort(Y.begin(), Y.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        

        cout << "Case #" << t + 1 << ": ";

        for (int i = 0; i < N; ++i) cout << Y[i].first + 1 << " ";
        cout << endl;
    }
}
