#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> P(1001, 0);
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        ++P[l];
    }
    
    int m = 0;
    
    for (int i = 1; i < 1001; ++i) m = max(m, P[i]);
    
    int c = 0;
    
    for (int i = 1; i < 1001; ++i) if (P[i] > 0) ++c;
    
    cout << m << " " << c << endl;
}
