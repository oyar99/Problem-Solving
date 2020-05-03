class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int count = 0;
        
        int n = light.size();
        
        int m = 0;
        
        
        for (int i = 0; i < n; ++i) {
            m = max(m, light[i]);
        
            if (light[i] <= i + 1 && m == i + 1) ++count;
        }
        return count;
    }
};
