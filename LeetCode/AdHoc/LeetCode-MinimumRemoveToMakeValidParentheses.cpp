class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string sol = "";
        int balance = 0;
        
        for (const char& c: s) {
            if (c == '(') {
                ++balance;
            } else if (c == ')') {
                if (balance - 1 < 0) continue;
                
                --balance;
            }
            
            sol += c;
        }
        
        if (balance == 0) return sol;
        
        assert(balance > 0);
        
        set<int> to_delete;
        
        for (int i = sol.size() - 1; i >= 0; --i) {
            if (balance <= 0) break;
            
            if (sol[i] == '(') to_delete.insert(i), --balance;
        }
        
        assert(balance == 0);
        
        string ans = "";
        
        for (int i = 0; i < sol.size(); ++i) {
            if (to_delete.count(i) > 0) continue;
            
            ans += sol[i];
        }
        
        return ans;
    }
};
