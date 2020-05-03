class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();
        
        int r = 0;
        set<int> seen;
        seen.insert(0);
        multiset<int> s;
        s.insert(nums[0]);
        
        int ans = 0;
        
        for (int l = 0; l < n; ++l) {
            
            if (l > r) ++r;
            
            while (r < nums.size() && (s.empty() || (*(--s.end()) - *(s.begin()) <= limit))) {
                
                
                if (seen.count(r) <= 0) {
                    s.insert(nums[r]);
                    seen.insert(r);
                }
                
                if (*(--s.end()) - *(s.begin()) > limit) break;
                
                ++r; 
            }

            ans = max(ans, r - l);            
            s.erase(s.find(nums[l]));
            
        }
        return ans;       
    }
};
