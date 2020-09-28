class Solution {
public:
    vector<int> findAnagrams(const string& s, const string& p) {
        
        if (p.size() > s.size()) return {};
        
        vector<int> ans;
        ans.reserve(s.size());
        
        int mp[26];
        memset(mp, 0, sizeof(mp));
        
        for (int i = 0; i < p.size();++i) {
            mp[p[i]-'a']++;
        }
        
        int m[26];
        memset(m, 0, sizeof(m));
        
        for (int i = 0; i < p.size(); ++i) {
            m[s[i]-'a']++;
        }
        
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        
        for (int i = 1; i < s.size() - p.size() + 1; ++i) {
            bool valid = true;
            for (char c: alphabet) {
                if (mp[c-'a'] != m[c-'a']) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) ans.push_back(i-1);
            
            m[s[i-1]-'a']--;
            m[s[i + p.size() - 1]-'a']++;
        }
        
        bool valid = true;
        for (char c: alphabet) {
            if (mp[c-'a'] != m[c-'a']) {
                valid = false;
                break;
            }
        }
            
        if (valid) ans.push_back(s.size() - p.size());
        
        return ans;
    }
};
