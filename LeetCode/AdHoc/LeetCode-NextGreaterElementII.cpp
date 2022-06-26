class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nextGreater(nums.size(), -1);
        stack<int> s;
        
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                nextGreater[s.top()] = nums[i];
                s.pop();
            }
            
            s.push(i);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && s.top() > i && nums[i] > nums[s.top()]) {
                nextGreater[s.top()] = nums[i];
                s.pop();
            }
        }
        
        return nextGreater;
    }
};
