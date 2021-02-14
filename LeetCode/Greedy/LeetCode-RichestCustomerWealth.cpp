class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealthiest = 0;
        
        for (int i = 0; i < accounts.size(); ++i)
            wealthiest = max(wealthiest, accumulate(accounts[i].begin(), accounts[i].end(), 0));
                
        return wealthiest;
    }
};
