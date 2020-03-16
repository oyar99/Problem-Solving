#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T; cin >> T;
 
    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        vector<int> v(n);
 
        for (int i = 0; i < n; ++i) cin >> v[i];
        
        unordered_map<int, unordered_set<int>> m;
        
        for (int i = 0; i < n; ++i) m[v[i]].insert(i);
        bool ans = false;
        for (int i = 0; i < n; ++i) {
            bool palindrome = false;
            for (int j: m[v[i]]) {
                if (abs(j - i) > 1) {
                    palindrome = true;
                    break;
                }
            }
            
            ans = palindrome;
            
            if (palindrome) break;
        }
 
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
