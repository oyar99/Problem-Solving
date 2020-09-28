#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
//URI 1492

int count_ones_up_to(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int len = ceil(log2(n));
    int p = 1;
    int t = 0;
    for (int i = 0; i < len + 1;++i, p *= 2) {
        int s = ceil(n / p);
        int b = 0;
        if (s & 1) b += (s >> 1) * p + (n % p) + 1;
        else b += (s >> 1) * p;
        t+=b;
    }
    return t;
}

#undef int
int main() {
#define int long long
    int a, b;
    while (cin >> a) {
        cin >> b;
        int na = count_ones_up_to(a-1);
        int nb = count_ones_up_to(b);
        cout << nb - na << endl;
    }
}
