#include <iostream>
#include <vector>
#include <cmath>

#define int long long

using namespace std;

struct chapter {
    int l;
    int r;
};

#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<chapter> book(n);
    for (int i = 0; i < n;++i) {
        int l, r; cin >> l >> r;
        book[i] = {l, r};
    }

    int k; cin >> k;

    for (int i = 0; i < n;++i) {
        if (book[i].l <= k && book[i].r >= k) {cout << n - i << endl; break;}
    }

    return 0;
}