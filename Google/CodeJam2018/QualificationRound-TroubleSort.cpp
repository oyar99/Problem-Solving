#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        vector<int> L(N);

        for (int i = 0; i < N;++i) {
            int v; cin >> v;
            L[i] = v;
        }
        
        vector<int> odds;
        vector<int> evens;

        for (int i = 0; i < N; i+=2) odds.push_back(L[i]);
        for (int i = 1; i < N; i+=2) evens.push_back(L[i]);

        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());

        for (int i = 0, j = 0; i < N; i+=2, ++j) L[i] = odds[j];
        for (int i = 1, j = 0; i < N; i+=2, ++j) L[i] = evens[j];

        int index = -1;
        for (int i = 0; i < N - 1; ++i) {
            if (L[i+1] < L[i]) {
                index = i;
                break;
            }
        }

        if (index == -1) cout << "Case #" << (t+1) << ": OK" << endl;
        else cout << "Case #" << (t+1) << ": " << index << endl; 
    }
}