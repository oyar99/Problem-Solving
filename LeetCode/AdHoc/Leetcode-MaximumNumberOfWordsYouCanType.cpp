class Solution {
public:
    int canBeTypedWords(const string& text, const string& brokenLetters) {
        int count = 0;
        
        vector<bool> broken(26);
        
        for (const char& i : brokenLetters) broken[i - 'a'] = true;
        
        bool complete = true;
        
        for (const char& c : text+' ') {
            if (c == ' ') {
                if (complete) ++count;
                complete = true;
                continue;
            }
            complete = complete && !broken[c - 'a'];
        }
        
        return count;
    }
};
