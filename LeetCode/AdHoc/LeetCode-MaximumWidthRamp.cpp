class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> v;
        map<int, int> mp;
        
        int m = -1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] > m) {
                v.push_back(m + 1);
                v.push_back(nums[i]);
                mp[m+1] = i;
                mp[nums[i]] = i;
                m = nums[i];
            }
        }
        
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int j = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            ans = max(ans, mp[v[j]] - i);
        }
        
        return ans;
    }
};
