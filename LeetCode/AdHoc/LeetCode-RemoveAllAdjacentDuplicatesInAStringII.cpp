class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        list<char> w;
        
        for (int i = 0; i < s.size(); ++i) {
            w.push_back(s[i]);
        }
        
        stack<int> st;
        int r = 1;
        
        st.push(r);
        for (auto it = next(w.begin()); it != w.end();) {
            if (*it == *prev(it)) {
                ++r;
            } else {
                st.push(r);
                r = 1;
            }
            
            if (r == k) {
                auto l = it;
                advance(l, - k + 1);
                it = w.erase(l, next(it));
                r = st.top();
                st.pop();
            } else {
                advance(it, 1);
            }
        }
        
        string ans;
        
        for (auto it = w.begin(); it != w.end(); ++it) {
            ans.push_back(*it);
        }
        
        return ans;
    }
};
