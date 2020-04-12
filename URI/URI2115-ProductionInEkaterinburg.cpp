#include <bits/stdc++.h>

using namespace std;

struct task {
    int d;
    int p;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n) {
        vector<task> T(n);

        for (int i = 0; i < n; ++i) {
            int d, p; cin >> d >> p;
            T[i] = {d, p};
        }

        sort(T.begin(), T.end(), [](const auto& a, const auto& b) {
            return a.d < b.d;
        });

        int t = 1;

        for (int i = 0; i < T.size(); ++i) {
            t = max(t, T[i].d);

            t += T[i].p;
        }

        cout << t << endl;
    }
}
