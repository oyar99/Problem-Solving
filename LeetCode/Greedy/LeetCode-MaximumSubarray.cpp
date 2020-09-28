class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = INT32_MIN;
        int s = 0;
        for (int i = 0; i < nums.size();++i) {
            s += nums[i];
            
            if (nums[i] > s) s = nums[i];
            
            m = max(m, s);
        }
        return m;
    }
};