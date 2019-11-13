#include <iostream>
#include <vector>

#pragma GCC Optmize("03")


using namespace std;

#define int long long


int find_max_profit(vector<int>& prices, int c, int i, bool own, vector<vector<int>>& memo) {
    if (i >= prices.size()) return 0;

    if (memo[i][own] != INT64_MIN) return memo[i][own];
    
    if (own) {
        int hold = find_max_profit(prices, c, i+1, true, memo);
        int sell = find_max_profit(prices, c, i+1, false, memo) + prices[i];
        int best = max(hold, sell);
        memo[i][own] = best;
        return best;
    }
    else {
        int buy = find_max_profit(prices, c, i+1, true, memo) - prices[i] - c;
        int hold = find_max_profit(prices, c, i+1, false, memo);
        int best = max(buy, hold);
        memo[i][own] = best;
        return best;
    }
}

#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;

    while (cin >> N >> C) {
        vector<int> prices(N);

        for (int i = 0; i < N;++i) {
            int p; cin >> p;
            prices[i] = p;
        }
        vector<vector<int>> memo(N, vector<int>(2, INT64_MIN));
        int ans = find_max_profit(prices, C, 0, false, memo);
        cout << ans << endl;
    }


    return 0;
}