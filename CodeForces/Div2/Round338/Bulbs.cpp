#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <algorithm>

#define int long long

using namespace std;


#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> bulbs(m);

    for (int i = 0; i < n;++i) {
        int s; cin >> s;
        for (int j = 0; j < s;++j) {
            int bulb; cin >> bulb;
            bulbs[bulb-1] = 1;
        }
    }

    bool all = true;
    for (int i = 0; i < m;++i) {
        if (!bulbs[i]) {all = false; break;}
    }

    if (all) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}