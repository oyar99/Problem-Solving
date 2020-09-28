#include <bits/stdc++.h>

using namespace std;

int damage(const string& s) {
    int c = 1;
    int d = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'C') c*=2;
        else d+=c;
    }
    return d;
}


int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T;++t) {
        int D; cin >> D;
        string P; cin >> P;
        int count = 0;
        if (damage(P) > D) { 
            for (int i = P.size() - 1; i > 0; --i) {
                if (P[i] == 'S' && P[i-1] == 'C') {
                    ++count;
                    char temp = P[i];
                    P[i] = P[i-1];
                    P[i-1] = temp;
                    if (damage(P) <= D) break;
                    i = P.size();
                }
            }
        }
        
        if (damage(P) <= D) cout << "Case #" << (t+1) << ": " << count << endl;
        else cout << "Case #" << (t+1) << ": IMPOSSIBLE" << endl;
    }
}