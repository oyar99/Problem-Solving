class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> m;
        
        for (int i = 1; i <= n; ++i) {
            int k = i;
            int s = 0;
            
            while (k > 0) {
                s += k % 10;
                k /= 10;
            }
            
            m[s]++;
        }
        
        int ma = INT32_MIN;
        int g = 0;
        
        for (const auto& e: m) {
            if (e.second == ma) ++g;
            else if (e.second > ma) g = 1, ma = e.second;
        }
        
        return g;

    }
};
