class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        bool m [n+1];
        
        memset(m, 0, n+1);
        
        int s = n * (n+1) >> 1;
        int s2 = 0;
        int k = 0;
        
        for (int a : nums) {
            if (m[a]) k = a;
            m[a] = true;
            s2 += a;
        }
        
        return {k, k + (s - s2)};
    }
};
