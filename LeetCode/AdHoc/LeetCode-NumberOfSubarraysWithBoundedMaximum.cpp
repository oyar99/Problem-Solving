class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<int> v(A.size(), 1);
        //1 means it is a valid starting point of a subarray
        //2 means it cannot be part of a subarray
        //3 means it could be in a subarray
        
        
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) v[i] = 2;
            else if (A[i] < L) v[i] = 3;
        }
        
        int count = 0;
        int sz = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (v[i] == 2) {
                count += (sz * (sz+1)) >> 1;
                sz = 0;
            } else {
                ++sz;
            }
        }
        count += (sz * (sz + 1)) >> 1;
        
        if (count == 0) return 0;
        
        sz = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (v[i] == 1 || v[i] == 2) {
                count -= (sz * (sz + 1)) >> 1;
                sz = 0;
            } else {
                ++sz;
            }
        }
        
        count -= (sz * (sz + 1)) >> 1;
        return count;
    }
};
