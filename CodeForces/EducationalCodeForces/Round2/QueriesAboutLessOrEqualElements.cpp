#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <algorithm>

#define int long long

using namespace std;


#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n;++i) {
        int e; cin >> e;
        A[i] = e;
    }

    for (int i = 0; i < m;++i) {
        int e; cin >> e;
        B[i] = e;
    }

    sort(A.begin(), A.end());


    for (int i = 0; i < m;++i) {
        int p = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
        if (i < m - 1) cout << p << " ";
        else cout << p << endl;
    }


    return 0;
}