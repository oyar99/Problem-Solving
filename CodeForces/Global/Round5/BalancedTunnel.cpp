#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;

    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; ++i) cin >> v1[i];
    for (int i = 0; i < n; ++i) cin >> v2[i];

    unordered_set<int> fine;
    unordered_set<int> seen;

    for (int i = 0, j = 0; i < n;++i) {
        if (fine.count(v1[i]) > 0) continue;
        seen.insert(v1[i]);

        while (j < n && v1[i] != v2[j]) {
            if (seen.count(v2[j]) <= 0) fine.insert(v2[j]);
            ++j;
        }
    }

    cout << fine.size() << endl;
        
    return 0;
}
