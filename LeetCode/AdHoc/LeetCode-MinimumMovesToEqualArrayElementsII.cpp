class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int m = nums.size() & 1 ? nums[nums.size() >> 1]: (nums[nums.size() >> 1] + nums[(nums.size() >> 1) - 1]) >> 1;
        int count = 0;
        
        for_each(nums.begin(), nums.end(), [&](int a) {
           count += abs(a - m); 
        });
        
        return count;
    }
};
