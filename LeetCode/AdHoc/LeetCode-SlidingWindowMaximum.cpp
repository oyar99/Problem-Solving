class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0) return {};
        vector<int> log(nums.size() + 1);
        log[1] = 0; 
        for (int i = 2; i <= nums.size(); ++i) {
            log[i] = log[i / 2] + 1;
        }
        
        vector<vector<int>> T(log[nums.size()] + 1, vector<int>(nums.size()));
        
        for (int j = 0; j < nums.size(); ++j) T[0][j] = nums[j];
        
        for (int i = 1; i <= log[nums.size()]; ++i) {
            for (int j = 0; j < nums.size() - (1 << i) + 1; ++j) {
                T[i][j] = max(T[i-1][j], T[i-1][j + ((1 << i) >> 1)]);
            }
        }
        
        vector<int> ans;
        for (int q = 0; q < nums.size() - k + 1; ++q) {
            int m = max(T[log[k]][q], T[log[k]][(q + k) - (1 << log[k])]);
            ans.push_back(m);
        }
        return ans;
    }
};
