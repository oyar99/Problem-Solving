#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_prime [(int)10e6+1];

void get_primes(vector<ll>& primes) {
    
    for (ll i = 0; i < 10e6; ++i) is_prime[i] = true;
    
    for (ll i = 2; i * i <= 10e6; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i, k = 0; j <= 10e6; ++k, j += k * i) {
                is_prime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= 10e6; ++i) if (is_prime[i]) primes.push_back(i);
} 

ll num_factors(ll n, vector<ll>& primes) {
    ll factors = 0;
    for (ll i = 0; i < primes.size(); ++i) {
        while (n % primes[i] == 0) {
            n /= primes[i];
            ++factors;
        }

        if (n == 1 || primes[i] * primes[i] > n) break;
    }
    if (n > 1) ++factors;
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> primes;
    primes.reserve(9683004);
    get_primes(primes);

    while (1) {

        ll n; cin >> n;

        if (n == 1) break;

        ll ans = num_factors(n, primes);

        cout << ans << endl;
    }
}
