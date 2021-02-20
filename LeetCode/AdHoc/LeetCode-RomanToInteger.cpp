class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int prev = m[s[0]];
        int ans = 0;
        
        for (const char& c: s) {
            if (m[c] > prev) ans += m[c] - 2 * prev;
            else ans += m[c];
            prev = m[c];
        }
        
        return ans;
    }
};
