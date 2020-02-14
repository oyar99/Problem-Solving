#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        string a, b, c; cin >> a >> b >> c;
        int n = a.size();
        
        bool pos = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i] && a[i] != c[i]) {
                pos = false;
                break;
            }
            if (!(c[i] == a[i] || c[i] == b[i])) {
                pos = false;
                break;
            } 
        }
        
        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
