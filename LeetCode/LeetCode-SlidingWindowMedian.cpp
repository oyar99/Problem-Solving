class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> meds(nums.size() - k + 1);
        multiset<long long> tree;
        
        for (int i = 0; i < k;++i) {
            tree.insert(nums[i]);
        }
        
        auto it = tree.begin();
        advance(it, tree.size() / 2);
        
        for (int i = 0; i < nums.size() - k + 1; ++i) {
            if ( i > 0) {
                tree.erase(tree.lower_bound(nums[i-1]));
                tree.insert(nums[i+k-1]);
                it = tree.begin();
                advance(it, tree.size() / 2);
            }
            double med;
            if (k & 1) med = *it;
            else med = (double)(*(--it) + *(++it)) / 2.f;
            meds[i] = med;
        }
        return meds;
    }
};