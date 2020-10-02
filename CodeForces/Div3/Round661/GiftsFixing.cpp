#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define INF (ll)10e10+1
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        vector<ll> a(n);
        
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<ll> b(n);

        for (int i = 0; i < n; ++i) cin >> b[i];

        ll m_a = INF;
        ll m_b = INF;
        
        for (int i = 0; i < n; ++i) m_a = min(m_a, a[i]), m_b = min(m_b, b[i]);

        ll ans = 0;

        for (int i = 0; i < n; ++i) ans += min(a[i] - m_a, b[i] - m_b) + ((a[i] - min(a[i] - m_a, b[i] - m_b)) - m_a) + ((b[i] - min(a[i] - m_a, b[i] - m_b)) - m_b);

        cout << ans << endl; 
        
    }
}