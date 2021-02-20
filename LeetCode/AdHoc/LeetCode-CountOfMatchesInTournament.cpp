class Solution {
public:
    int numberOfMatches(int n) {
        int m = 0;
        
        while (n-1)
            if (n & 1)
                m += (n - 1) >> 1, n = ((n - 1) >> 1) + 1;
            else
                m += n >> 1, n = n >> 1;
        
        return m;
    }
};
