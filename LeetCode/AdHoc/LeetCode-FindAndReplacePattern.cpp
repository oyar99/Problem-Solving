class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, const string& pattern) {
        vector<string> ans;
        ans.reserve(words.size());
        
        for (const string& w: words) {            
            unordered_map<char, char> m;
            
            bool pos = true;
            
            for (int i = 0; i < w.size() && pos; ++i)
                pos = !(m.count(w[i]) && m[w[i]] != pattern[i]),
                m[w[i]] = pattern[i];
            
            if (!pos) continue;
            
            unordered_set<char> s;
            
            for (const auto& e: m) {
                pos = !s.count(e.second);
                if (!pos) break;
                s.insert(e.second);
            }
            
            if (pos) ans.push_back(w);
        }
        
        return ans;
    }
};
