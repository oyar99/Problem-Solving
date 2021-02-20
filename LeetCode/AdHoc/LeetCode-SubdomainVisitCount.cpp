class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m;
        
        for (const string& s: cpdomains) {
            string num, dom;
            
            bool after = false;
            
            for (const char& c: s)
                if (after) dom += c;
                else
                    if (c == ' ') after = true;
                    else num += c;
            
            int n = stoi(num);
            
            string d;
            
            for (int i = dom.size() - 1; i >= 0; --i) {
                if (dom[i] == '.') m[d] += n;
                d += dom[i];
            }
            
            m[d] += n;
        }
        
        vector<string> v;
        
        for (pair<string, int> e: m) { 
            reverse(e.first.begin(), e.first.end()); 
            v.push_back(to_string(e.second) + " " + e.first);
        }
        
        return v;
    }
};
