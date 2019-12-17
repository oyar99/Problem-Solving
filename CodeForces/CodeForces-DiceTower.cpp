#include <bits/stdc++.h>
    
using namespace std;

    
bool solve(long long x) {
    if (x <= 14) return false;
    
    long long l = x % 14;
    
    if (l >= 1 && l <= 6) return true;
    
    return false;
}
    
int main() {
    int t; cin >> t;
    
    for (int i = 0; i < t; ++i) {
        long long x; cin >> x;
        bool ans = solve(x);
    
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

