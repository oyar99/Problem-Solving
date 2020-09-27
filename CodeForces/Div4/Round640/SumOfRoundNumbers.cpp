#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        string s; cin >> s;

        vector<int> ans;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] != '0') {
                ans.push_back((s[i] - '0') * pow(10, s.size() - i - 1));
            }
        }

        cout << ans.size() << endl;

        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;


    }
}
