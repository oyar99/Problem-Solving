class Solution {
public:
    vector<int> constructArray(int n, int k) {
        
        vector<int> v(n);
        
        int sml = 1;
        int lrg = n;
        
        for (int i = 0; i < k; ++i) {
            if (i & 1) v[i] = lrg--;
            else v[i] = sml++;
        }
        
        for (int i = k; i < n; ++i) {
            if (k & 1) v[i] = v[i-1] + 1;
            else v[i] = v[i-1] - 1;
        }
        
        return v;
    }
};
