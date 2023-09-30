#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int n; int k; cin >> n >> k;
        
        bool ans = false;
        
        for (int i = 0; i < n; ++i) {
            int u; cin >> u;
            
            if (u == k && !ans) {
                cout << "Yes" << endl;
                ans = true;
            }
        }
        
        if (!ans) cout << "No" << endl;
    }
}
