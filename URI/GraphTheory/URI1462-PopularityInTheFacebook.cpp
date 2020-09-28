#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define int long long

using namespace std;


/*
    Erdos-Gallai Theorem

    A sequence of integers is the degree sequence of a simple graph iff d1 + d2 + ... + dn is even and 
    Σ i=1 to k (di) <= k(k - 1) + Σ i = k + 1 to n (min(di, k))
*/

bool solve(vector<int>& list, int sum) {
    if (sum & 1) return false;

    sort(list.begin(), list.end(), greater<int>());

    vector<int> sum_up_to(list.size());

    sum_up_to[0] = list[0];

    for (int i = 1; i < list.size(); ++i) sum_up_to[i] = sum_up_to[i-1] + list[i];

    for (int k = 1; k <= list.size();++k) {
        int l = sum_up_to[k-1];
        int p = lower_bound(list.begin() + k, list.end(), k, greater<int>()) - (list.begin() + k);

        int val = p * k + ((p + k - 1 > sum_up_to.size()) ? 0: sum_up_to.back() - sum_up_to[p + k - 1]);
        int r = k * (k - 1) + val;
        
        if (l > r) return false;
    }
    return true;
}

#undef int
int main() {
    #define int long long
    int n;
    while (cin >> n) {
        bool possible = true;
        int sum = 0;
        vector<int> list(n);
        for (int i = 0; i < n;++i) {
            int c; cin >> c;
            list[i] = c;
            if (c >= n) possible = false;
            sum += c;
        }

        if (!possible) {
            cout << "impossivel" << endl;
            continue;
        }


        if (solve(list, sum)) cout << "possivel" << endl;
        else cout << "impossivel" << endl;
    }
}
