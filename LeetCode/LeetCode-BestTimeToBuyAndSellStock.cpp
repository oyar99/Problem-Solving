class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int p = 0;
        int m = 0;
        for (int i = prices.size() - 1; i > 0; --i) {
            m = max(m, prices[i]);
            p = max(p, m - prices[i-1]);
        }
        return p;
    }
};