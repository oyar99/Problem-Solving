#include <iostream>
#include <vector>
#include <cmath>

#define int long long

using namespace std;

#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    int even = 0;
    int odd = 0;
    for (int i = 0;i < n;++i) {
        int c; cin >> c;
        if (c & 1) ++odd;
        else ++even;
    }

    if (odd & 1) cout << odd << endl;
    else cout << even << endl;

    return 0;
}