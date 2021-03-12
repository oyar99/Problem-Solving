class Solution {
public:
    bool hasAllCodes(const string& s, int k) {
        
        // Time: O(nk+2^k)
        // Space: O(2^k)
        
        int n = s.size();
        
        bool seen [1 << k];
        memset(seen, 0, sizeof(seen));
        
        for (int i = 0; i < n - k + 1; ++i) {
            
            int cur = 0;
            for (int j = 0; j < k; ++j)
                cur += (s[j+i] == '1' ? 1 << (k - j - 1) : 0);
            
            seen[cur] = 1;
        }
        
        for (int i = 0; i < (1 << k); ++i)
            if (!seen[i]) return false;
        
        return true;
    }
};
