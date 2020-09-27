#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        int sum = 0;
        while (n > 0) {
            string s = to_string(n);

            string b = "";
            b += s[0];

            for (int i = 0; i < s.size() - 1; ++i) b += "0";

            int d = stoi(b);

            sum += d;

            int c = d / 10;

            n = n - d + c;
        }
        cout << sum << endl;
    }
}