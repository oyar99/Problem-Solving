#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        
        int m = 10;
        int ans = 1;
        
        int zeroes = 0;
        
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            
            m = min(m, x);
            if (x == 0) ++zeroes;
            if (x > 0) ans *= x;
        }
        
        if (zeroes >= 2) {
            ans = 0;
        } else if (zeroes <= 0) {
            ans = ans/m * (m + 1);
        }
        cout << ans << endl;
    }
}
