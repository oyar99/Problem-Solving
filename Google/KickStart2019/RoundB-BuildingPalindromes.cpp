#include <bits/stdc++.h>

using namespace std;

struct Prefix {
    vector<vector<int>> D;

    Prefix(string& s, int sz) {
        D = vector<vector<int>>(26, vector<int>(sz+1));

        for (int i = 1; i <= sz; ++i) {
            int pos = s[i-1] - 'A';
            for (int j = 0; j < 26; ++j) {
                if (pos != j) D[j][i] = D[j][i-1];
                else D[j][i] = D[j][i-1] + 1;
            }
        }
    }

    bool can_build_palindrome(int l, int r) {
        vector<int> count(26);

        for (int i = 0; i < 26; ++i) count[i] = D[i][r] - D[i][l-1];

        bool one_odd = false;

        for (int i = 0; i < 26; ++i) {
            if (count[i] <= 0) continue;

            if (count[i] & 1 && one_odd) return false;

            if (count[i] & 1) one_odd = true;
        }
        return true;
    }
};

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, Q; cin >> N >> Q;
        string s; cin >> s;

        Prefix p(s, N);

        int count = 0;

        for (int q = 0; q < Q; ++q) {
            int l, r; cin >> l >> r;

            if (p.can_build_palindrome(l, r)) ++count;
        }

        cout << "Case #" << (t+1) << ": " << count << endl;
    }
}