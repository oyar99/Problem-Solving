#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 

    while (cin >> n) {
        multiset<pair<int, int>> m;

        int count = 0;
        for (int i = 0; i < n; ++i) {
            int l; cin >> l;
            char e; cin >> e;
            int p = e == 'D' ? 1:-1;
            if (m.count({l, -p}) > 0) {
                ++count;
                m.erase(m.find({l, -p}));
            } else {
                m.insert({l, p});
            }
        }

        cout << count << endl;
        
    }


}
