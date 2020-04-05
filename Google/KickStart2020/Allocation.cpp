#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N, B; cin >> N >> B;
        
        vector<int> h(N);
        
        for (int i = 0; i < N; ++i) cin >> h[i];
        
        sort(h.begin(), h.end());
        
        int j = N;
        for (int i = 0; i < N; ++i) {
            if (h[i] <= B) {
                B -= h[i];
            } else {
                j = i;
                break;
            }
        }
        cout << "Case #" << t << ": " << j << endl;
    }
}
