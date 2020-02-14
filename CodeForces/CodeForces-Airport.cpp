#include <bits/stdc++.h>
 
using namespace std;
 
int sum_up_to(int n) {
    return n * (n+1) / 2;
}
 
int max_profit(int n, vector<int>& R) {
    int r = 0;
    vector<int> A(1001, 0);
    
    for (int i = 0; i < R.size(); ++i) ++A[R[i]];
    
    for (int i = 1000; i > 0; --i) {
        if (A[i] <= n) {
            r += (i * A[i]);
            A[i-1] += A[i];
            n -= A[i];
        } else {
            r += (i * n);
            break;
        }
    }
    return r;
}
 
int min_profit(int n, vector<int> R) {
    sort(R.begin(), R.end());
    int r = 0;
    
    for (int i = 0; i < R.size(); ++i) {
        if (n >= R[i]) {
            r += sum_up_to(min(R[i], n));
            n = max(n - R[i], 0);
        } else {
            while (n > 0) {
                r += R[i];
                --R[i];
                --n;
            }
        }
    }
    return r;
}
 
int main() {
    int n; cin >> n;
    int p; cin >> p;
    
    vector<int> R(p);
    
    for (int i = 0; i < p; ++i) {
        int s; cin >> s;
        R[i] = s;
    }

    int maxr = max_profit(n, R);
    int minr = min_profit(n, R);
    
    
    cout << maxr << " " << minr << endl;
    
}
