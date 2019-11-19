#include <iostream>
#include <vector>

using namespace std;

#define int long long

int max_profit(const vector<int>& stock, const int k ,int i, bool has_share, int curr_k, vector<vector<vector<int>>>& memo) {
   if (i >= stock.size()) return 0;
   if (curr_k >= k) return 0;

   if (memo[i][has_share][curr_k] != INT64_MIN) return memo[i][has_share][curr_k];

   if (has_share) {
       int keep = max_profit(stock, k, i + 1, true, curr_k, memo);
       int sell = max_profit(stock, k, i + 1, false, curr_k + 1, memo) + stock[i];
       int best_decision = max(keep, sell);
       memo[i][has_share][curr_k] = best_decision;
       return best_decision;
   } else {
       int let_go = max_profit(stock, k, i + 1, false, curr_k, memo);
       int buy = max_profit(stock, k, i + 1, true, curr_k, memo) - stock[i];
       int best_decision = max(let_go, buy);
       memo[i][has_share][curr_k] = best_decision;
       return best_decision;
   }
}

#undef int
int main() {
    #define int long long

    int n, k; cin >> n >> k;

    vector<int> stock(n);

    for (int i = 0; i < n;++i) {
        int p; cin >> p;
        stock[i] = p;
    }
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(k, INT64_MIN)));

    cout << max_profit(stock, k, 0, false, 0, memo) << endl;

}