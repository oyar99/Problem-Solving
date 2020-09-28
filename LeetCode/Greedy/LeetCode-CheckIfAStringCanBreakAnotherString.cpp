class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        int n = s1.size();
        
        bool first = true;
        
        for (int i = 0; i < n; ++i) {
            if (s1[i] < s2[i]) {
                first = false;
                break;
            }
        }
        
        if (first) return true;
        
        bool second = true;
        
        for (int i = 0; i < n; ++i) {
            if (s2[i] < s1[i]) {
                second = false;
                break;
            }
        }
        
        if (second) return true;
        return false;
    }
};
