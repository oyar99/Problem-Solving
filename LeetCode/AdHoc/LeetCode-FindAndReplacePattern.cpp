class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, const string& pattern) {
        vector<string> ans;
        
        for (const string& w: words) {            
            unordered_map<char, char> m;
            
            bool pos = true;
            
            for (int i = 0; i < w.size(); ++i) {
                if (m.count(w[i])) {
                    if (m[w[i]] != pattern[i]) {
                        pos = false;
                        break;
                    }
                } else {
                    m[w[i]] = pattern[i];
                }
            }
            
            unordered_set<char> s;
            
            for (const auto& e: m) {
                if (s.count(e.second)) {
                    pos = false;
                    break;
                }
                s.insert(e.second);
            }
            
            if (pos) ans.push_back(w);
        }
        
        return ans;
    }
};
