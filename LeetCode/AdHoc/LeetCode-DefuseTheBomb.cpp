class Solution {
    vector<int> _P;
    
    void init_P(vector<int>& code) {
        int n = code.size();
        _P = vector<int>(n+1);
        _P[0] = code[0];
        
        for (int i = 1; i < n; ++i) _P[i] = _P[i-1] + code[i];
        
        _P[n] = _P[n-1];
    }
    
    int P(int i) {
        return i == -1 ? 0 : _P[i];
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // use a prefix sum array to compute the sum of the next/previous k numbers for every number at index i
        int n = code.size();
        
        init_P(code);
        
        vector<int> R(n);
        
        if (k == 0) return R;
        
        //By definition, P(-1) = 0 && P(n) = P(n-1) 
        
        //k > 0 - Sum of next k numbers
        // The sum of next k numbers to the right is P(min(i+k, n-1)) - P(i)
        // The sum of next k numbers to the left is P(max(-1,k-n+i))
        
        //K < 0 - Sum of previous k numbers
        // The sum of previous k numbers to the left is P(i-1)-P(max(-1,i+k-1))
        // The sum of previous k numbers to the right is P(n-1)-P(min(n,n-1+i+k))
        
        for (int i=0;i<n;++i)R[i]=k>0?P(max(-1,k-n+i))+P(min(i+k,n-1))-P(i):P(i-1)-P(max(-1,i+k-1))+P(n-1)-P(min(n,n-1+i+k));
        
        return R;
    }
};
