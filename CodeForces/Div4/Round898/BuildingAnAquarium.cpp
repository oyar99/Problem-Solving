#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int n; int x; cin >> n >> x;
        
        vector<ll> v(n);
        
        ll l = INT32_MAX;
        ll r = 10e9;
        
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            l = min(l, v[i]);
        }
        
        while (l < r) {
            ll h = (l + r) >> 1;
            
            ll cx = 0;
            
            for (int i = 0; i < n; ++i) {
                if (h > v[i]) {
                    cx += (h - v[i]);
                } 
            }
            
            if (cx > x) {
                r = h;
            } else {
                l = h + 1;
            }
        }
        
        cout << r - 1 << endl;
        
    }
}
