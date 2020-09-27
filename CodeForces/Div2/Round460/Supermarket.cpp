#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m; cin >> n >> m;
    
    double min_price = 0;
    double min_ratio = 2e60;
    
    for (int i = 0; i < n; ++i) {
        double a, b; cin >> a >> b;
        if ((a / b) < min_ratio) {
            min_ratio = (a/b);
            min_price = (min_ratio) * m;
        }
    }
    
    printf("%.6f", min_price);
    return 0;
}
