#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int t = 0; t < T;++t) {
        int n, x, a, b; cin >> n >> x >> a >> b;
        
        if (a > b) swap(a, b);

        int b_ = b;

        if (b < n) b = min(n, b + x);

        x = x - (b - b_);

        if (a > 1 && x > 0) a = max(1, a - x); 
        

        cout << b - a << endl;  
    }
    return 0;
}