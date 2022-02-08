class Solution {
public:
    int canBeTypedWords(const string& text, const string& brokenLetters) {
        int count = 0;
        
        vector<bool> broken(26);
        
        for (const char& i : brokenLetters) broken[i - 'a'] = 1;
        
        bool complete = 1;
        
        for (const char& c : text+' ') count += complete && c == ' ',complete = (complete || c == ' ') && (c == ' ' || !broken[c - 'a']);
        
        return count;
    }
};
