class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (m.count(k - nums[i]) > 0) {
                ++ans;
                --m[k-nums[i]];
                
                if (m[k-nums[i]] <= 0)
                    m.erase(k-nums[i]);
                
            } else {
                if (m.count(nums[i]) > 0)
                    ++m[nums[i]];
                else
                    m.insert({nums[i], 1});
            }
        }
        
        return ans;
    }
};
