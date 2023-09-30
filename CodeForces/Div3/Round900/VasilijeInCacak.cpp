#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        long long n; long long k; long long x; cin >> n >> k >> x;
        
        long long l = k * (k + 1) >> 1;
        long long r = (n * (n + 1) >> 1) - ((n - k) * (n - k + 1) >> 1);
        
        if (x >= l && x <= r) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
