#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;  cin >> n;
    bool good = false;
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        int b, a; cin >> b >> a;
        if (b >= 2400 && a > b) good = true;
    }
    
    if (good) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
