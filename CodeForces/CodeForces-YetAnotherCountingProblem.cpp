#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll largest_i(int b, ll f, ll w) {
    ll left = 0;
    ll right = 1e18+100;

    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (mid > w / (b * f)) right = mid;
        else left = mid + 1;
    }
    return left - 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        int Q; cin >> Q;

        ll f = min(a/gcd(a, b), b/gcd(a,b));
        
        for (int q = 0; q < Q; ++q) {
            ll l, r; cin >> l >> r;

            ll p = 0;
            
            ll i = largest_i(b, f, r);

            p = b * f * i;

            ll R = 0;

            if (i != 0) R += i * b;

            ll m = b;
            if (p + b > r) m = r + 1 - p;

            R += m;

            ll j = largest_i(b, f, l - 1);

            p = b * f * j;

            ll L = 0;
            
            if (j != 0) L = j * b;

            m = b;
            if (p + b > l - 1) m = l - p;

            L += m;

            cout << (r - l + 1 ) - (R - L) << " ";
        }
        cout << "\n";
    }
}
