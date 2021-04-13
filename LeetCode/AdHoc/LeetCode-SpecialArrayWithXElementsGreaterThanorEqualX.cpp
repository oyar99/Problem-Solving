class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i)
            if (nums[i] >= n - i && (i == 0 || n - i > nums[i-1])) 
                return n - i;
        
        return -1;
    }
};
