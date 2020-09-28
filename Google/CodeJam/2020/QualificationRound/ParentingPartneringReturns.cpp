#include <bits/stdc++.h>

using namespace std;

struct task {
    int l;
    int r;
    int i;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        vector<task> tasks(n);
        vector<char> v(n);
        for (int i = 0; i < n; ++i) {
            int l, r; cin >> l >> r;
            tasks[i] = {l, r, i};
        }

        sort(tasks.begin(), tasks.end(), [](const task& a, const task& b) {
            if (a.l == b.l) return a.r < b.r;
            return a.l < b.l;
        });

        int cr = 0;
        int jr = 0;
        string ans = "";
        bool pos = true;
        for (int i = 0; i < n; ++i) {
            if (cr <= tasks[i].l) {
                v[tasks[i].i] = 'C';
                cr = tasks[i].r;
            } else if (jr <= tasks[i].l) {
                v[tasks[i].i] = 'J';
                jr = tasks[i].r;
            } else {
                pos = false;
                break;
            }
        }

        if (pos) for (int i = 0; i < n; ++i) ans.push_back(v[i]);
        else ans = "IMPOSSIBLE";

        cout << "Case #" << t << ": " << ans << endl;
    }
}
