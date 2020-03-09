#define INF 100000

struct SegmentTree {
    vector<int> T;
    
    SegmentTree(int n) {
        T = vector<int>(n * 4, INF);
    }
    
    int query_min(int v, int tl, int tr, int l, int r) {
        if (l > r) return INF;
        
        if (l == tl && r == tr) return T[v];
        
        int tm = (tl + tr) >> 1;
        return min(query_min(v*2, tl, tm, l, min(r, tm)), query_min(v*2+1, tm + 1, tr, max(l, tm + 1), r));
    }
    
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            T[v] = val;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) update(v*2, tl, tm, pos, val);
            else update(v*2+1, tm+1, tr, pos, val);
            
            T[v] = min(T[v*2], T[v*2+1]);
        }
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        SegmentTree tree(nums.size());
        tree.update(1, 0, nums.size() - 1, 0, 0);
        
        //O(n*logn)
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] + i >= nums.size() - 1) tree.update(1, 0, nums.size() - 1, i, 1);
            else tree.update(1, 0, nums.size() - 1, i, tree.query_min(1, 0,  nums.size() - 1, i + 1, i + nums[i]) + 1);
        }
        
        return tree.query_min(1, 0, nums.size() - 1, 0, 0);
    }
};
