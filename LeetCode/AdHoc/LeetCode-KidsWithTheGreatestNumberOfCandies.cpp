class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();
        
        int m = 0;
        
        for (int i = 0; i < candies.size(); ++i) m = max(m, candies[i]);
        
        vector<bool> ans(n);
        
        for (int i = 0; i < candies.size(); ++i) {
            ans[i] = candies[i] + extraCandies >= m;
        }
        
        return ans;
    }
};
