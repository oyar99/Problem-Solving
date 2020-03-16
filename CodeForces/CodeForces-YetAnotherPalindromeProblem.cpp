#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; ++i) cin >> v[i];
        bool ans = false;
        for (int i = 0; i < n; ++i) {
            bool palindrome = false;
            for (int j = i + 1; j < n; ++j) {
                if (v[i] == v[j] && j - i > 1) {
                    palindrome = true;
                    break;
                } 
            }
            ans = palindrome;
            if (palindrome) break;
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}