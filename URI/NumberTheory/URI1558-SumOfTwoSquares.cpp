#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//Sum of two squares theorem

void prime_factors(int n, unordered_map<int, int>& m) {

    while (n % 2 == 0) {
        m[2]++;
        n /= 2;
    } 

    for (int i = 3; i * i <= n; i +=2) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }

    if (n > 2) m[n]++;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 

    while (cin >> N) {

        if (N < 0) {
            cout << "NO" << endl;
            continue;
        }

        if (N == 0) {
            cout << "YES" << endl;
            continue;
        }

        unordered_map<int, int> m;
        prime_factors(N, m);

        bool pos = true;
        for (const auto& e: m) {
            if (e.first % 4 == 3) {
                if (e.second & 1) {
                    pos = false;
                    break;
                }
            }
        }

        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
