struct ST {
    vector<vector<int>> T;
    vector<int> A;

    ST(vector<int>& A) {
        this->A = A;
        T = vector<vector<int>>(A.size() * 5);
        build(1, 0, A.size() - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            T[v].push_back(A[tl]);
        } else {
            int tm = (tl + tr) >> 1;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            merge(T[v*2].begin(), T[v*2].end(), T[v*2+1].begin(), T[v*2+1].end(), back_inserter(T[v]));
        }
    }

    int query(int v, int tl, int tr, int l, int r, int x) {
        if (l > r) return 0;
        if (tl == l && tr == r) return distance(T[v].begin(), lower_bound(T[v].begin(), T[v].end(), x));
        int tm = (tl + tr) >> 1;
        return query(v*2, tl, tm, l, min(r, tm), x) + query(v*2+1, tm+1, tr, max(l, tm+1), r, x);
    }
};

//Time complexity: O(nlg^2(n))
//Space complexity: O(nlgn)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        ST st(nums);
        
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) count += st.query(1, 0, nums.size()-1, i+1, nums.size() - 1, ceil(nums[i] / 2.f));
        
        return count;
    }
};
