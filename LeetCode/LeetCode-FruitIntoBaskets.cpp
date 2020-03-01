class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> m;
        int k = 0;
        int f = 0;
        for (int i = 0; i < tree.size(); ++i) {
            m[tree[i]]++;
            
            if (m.size() > 2) {
                m[tree[k]]--;
                if (m[tree[k]] <= 0) m.erase(tree[k]);
                ++k;
            } else {
                f = max(f, i - k + 1);
            }
        }
        return f;
    }
};
