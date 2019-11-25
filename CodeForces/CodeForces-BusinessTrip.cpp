#include <bits/stdc++.h>
 
using namespace std;
 
const int MONTHS = 12;
 
int main() {
    int k; cin >> k;
    vector<int> M(MONTHS);
    
    for (int i = 0; i < MONTHS; ++i) {
        int m; cin >> m;
        M[i] = m;
    }
    
    sort(M.begin(), M.end(), greater<int>());
    
    int q = 0;
    
    bool found = false;
    for (int i = 0; i < MONTHS + 1; ++i) {
        if (q >= k) {
            found = true;
            cout << i << endl;
            break;
        }
        if (i == MONTHS) break;
        q += M[i];
    }
    
    if (!found) cout << -1 << endl;
    
    return 0;
}
