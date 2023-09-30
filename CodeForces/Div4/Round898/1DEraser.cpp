#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int n; int k; cin >> n >> k;
        string s; cin >> s;
        
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') {
                ++count;
                i += k - 1;
            }
        }
        
        cout << count << endl;
    }
}
