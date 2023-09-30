#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        
        int p = 1;
        
        cout << p << " ";
        for (int i = 0; i < n - 1; ++i) {
            p = p + 4;
            
            if (i == n - 2) cout << p << endl;
            else cout << p << " ";
        }
    }
}
