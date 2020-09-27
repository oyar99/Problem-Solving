#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> V(n);
    
    for (int i = 0; i < n; ++i) cin >> V[i];
    
    int m = 0;
    int c = 1;
    int s = -1;
    
    for (int i = 0; i + 1 < n; ++i) {
        if (V[i+1] - V[i] > 1) {
            c = 1;
        } else {
            ++c;
            if (c > m) m = c, s = i - c + 2;
            if (c == m && i + 2 == n && V[V.size() - 1] == 1000) m = c, s = i - c + 2;  
        }
    }
    
    int ans = max(m - 2, 0);
    
    if (s == 0 && V[0] == 1) ans = m - 1;
    else if (s + c == n && V[V.size() - 1] == 1000) ans = m - 1;
    
    cout << ans << endl;
}
