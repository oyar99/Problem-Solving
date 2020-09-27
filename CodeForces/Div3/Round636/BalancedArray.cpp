#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;

        if ((n>>1)&1) {
            cout << "NO" << endl;
            continue;
        }

        vector<int> even = {2};
        vector<int> odds = {1};

        bool odd = false;

        for (int i = 1; i < (n>>1); ++i) {
            if (odd) {
                odds.push_back(odds.back() + 2);
                even.push_back(odds.back() + 1);
            } else {
                even.push_back(even.back() + 2);
                odds.push_back(even.back() + 1);
            }
            odd = !odd;
        }

        cout << "YES" << endl;

        for (int i = 0; i < even.size(); ++i) cout << even[i] << " ";
        for (int i = 0; i < odds.size(); ++i) cout << odds[i] << " ";
        cout << endl;
    }
}
