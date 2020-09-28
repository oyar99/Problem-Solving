//O(30n)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int t = 0;
        for (int i = 0; i < 31; ++i) {
            int count = 0;
            for (int j = 0; j < nums.size(); ++j) count += nums[j] >> i & 1;
            
            t += (nums.size() * (nums.size() - 1) >> 1) - ((count * (count - 1)) >> 1) - (((nums.size() - count) * (nums.size() - count - 1)) >> 1);
        } 
        return t;
    }
};
