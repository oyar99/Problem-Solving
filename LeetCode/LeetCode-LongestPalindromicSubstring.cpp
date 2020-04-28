class Solution {
public:
    string longestPalindrome(const string& s) {
        
        if (s.empty()) return "";
        
        int n = s.size();
        //number of palindromic substrings of odd length with center at i.
        vector<int> odd(n);
        //number of palindromic substrings of even length with center at i.
        vector<int> even(n-1);
        for (int i = 0; i < n; ++i) {
            int x = 0;
            
            while (i - x >= 0 && i + x < n && s[i-x] == s[i+x]) {
                odd[i]++;
                ++x;
            }
            
            if (i == n - 1) continue;
            
            if (s[i] != s[i+1]) continue;
            
            even[i] = 1;
            
            x = 1;
            
            while (i - x >= 0 && i + x + 1 < n && s[i-x] == s[i+x+1]) {
                even[i]++;
                ++x;
            }
            
        }
        
        
        int len = 0;
        int l = 0;
        
        for (int i = 0;i < odd.size(); ++i) {
            int length = 2 * odd[i] - 1;
            
            if (length > len) {
                len = length;
                l = i - len / 2;
            }
        }
        
        
        for (int i = 0; i < even.size(); ++i) {
            int length = 2 * even[i];
            
            if (length > len) {
                len = length;
                l = i - ((len / 2) - 1);
            }
        }
        return s.substr(l, len);
        
    }
};
