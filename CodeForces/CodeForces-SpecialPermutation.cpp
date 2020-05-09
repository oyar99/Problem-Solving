#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        
        if (n < 4) {
            cout << -1 << endl;
            continue;
        }
        
        deque<int> d = {2, 4, 1, 3};
        
        for (int i = 5; i <= n; ++i) {
            if (i&1) d.push_back(i);
            else d.push_front(i);
        }
        
        for (int i = 0; i < n; ++i) cout << d[i] << " ";
        cout << endl;
    }
}
