#include <iostream>
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
    int n; cin >> n;

    vector<int> coins(n);
    int sum = 0;
    for (int i = 0; i < n;++i) {
        int c; cin >> c;
        coins[i] = c;
        sum += c;
    }

    sort(coins.begin(), coins.end(), [](const int& a, const int& b) {return a > b;});

    int sum2 = 0;
    for (int i = 0; i < n;++i) {
        sum2 += coins[i];
        sum -= coins[i];

        if (sum2 > sum) {
            cout << (i+1) << endl;
            break;
        }
    }

    return 0;
}