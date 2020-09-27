#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    
    vector<int> S(n);
    
    for (int i = 0; i < n; ++i) cin >> S[i];
    
    unordered_set<int> U(m);
    
    for (int i = 0; i < m; ++i) {
        int u; cin >> u;
        U.insert(u);
    }
    
    for (int i = 0; i < n; ++i) {
        if (U.count(S[i]) > 0) cout << S[i] << " ";
    }
    cout << endl;
}
