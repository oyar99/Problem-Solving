#include <bits/stdc++.h>
 
using namespace std;
 
 
int main() {
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;
    bool found = false;
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200;++j) {
            if (b + a * i == d + c * j) {
                found = true;
                cout << b + a * i << endl;
                break;
            }
        }
        
        if (found) break;
    }
    
    if (!found) cout << -1 << endl;
    return 0;
}
