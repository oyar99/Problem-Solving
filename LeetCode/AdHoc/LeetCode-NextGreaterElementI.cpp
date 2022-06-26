class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreater(nums2.size(), -1);
        stack<int> s;
        map<int, int> m; // map values in nums2 to their indices
        
        for (int i = 0; i < nums2.size(); ++i) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                nextGreater[s.top()] = nums2[i];
                s.pop();
            }
            
            s.push(i);
            m[nums2[i]] = i;
        }
        
        vector<int> ans(nums1.size());
        
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = nextGreater[m[nums1[i]]];
        }
        
        return ans;
    }
};
