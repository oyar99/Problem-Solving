#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    stack<char> st;
    for (int t = 1; t <= T; ++t) {
        string s; cin >> s;
        int count = 0;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            int d = s[i] - '0';
            if (d == count) {
                st.push(s[i]);
                continue;
            }

            while (d > count) {
                st.push(')');
                ++count;
            }

            while (d < count) {
                st.push('(');
                --count;
            }
            st.push(s[i]);
        }

        while (count > 0) {
            st.push('(');
            --count;
        }

        string ans = "";

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}
