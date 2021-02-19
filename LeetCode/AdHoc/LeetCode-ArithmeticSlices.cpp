class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        if (A.size() <= 2) return 0;
        
        int slices = 0;
        int n = A.size();
        
        int diff = INT32_MAX;
        int length = 2;
        
        for (int i = 1; i < n; ++i) {
            int cur = A[i] - A[i-1];
            if (diff == INT32_MAX);
            else if (diff != cur) slices += length >= 3 ? (length - 2) * (length - 1) >> 1 : 0, length = 2;
            else ++length;
            diff = cur;
        }
        
        slices += length >= 3 ? (length - 2) * (length - 1) >> 1 : 0;
        
        return slices;
    }
};
