struct Solution {
    int score(const string& s, int i, int l) {
        
        if (i + l > s.size()) return 0;
        
        if (s.substr(i, l) == "()") return 1;
        
        int balance = 0;
        
        int k = i;
        
        for (int j = i + l; i < j; ++i) {
            if (s[i] == '(') ++balance;
            else --balance;
            
            if (balance == 0) {
                int left = i >= k + 2 ? score(s, k + 1, i - k) : score(s, k, i + 1 - k);
                int right = score(s, i + 1, j - (i + 1));
                
                return (i >= k + 2 ? 2: 1) * left + right;
            }
        }
        
        return 0;
    }
    
    int scoreOfParentheses(string s) {
        return score(s, 0, s.size());
    }
};
