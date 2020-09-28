class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        
        int r = 9;
        for (int i = 0; i < s.size(); ++i) {
            int d = s[i] - '0';
            
            if (d < 9) {
                r = d;
                break;
            }
        }
        
        string upper = s;
        
        for (int i = 0; i < s.size(); ++i) {
            if (upper[i] - '0' == r) upper[i] = '9';
        }
        
        int l = 0;
        bool ones = true;
        if (s[0] > '1') {
            l = s[0] - '0';
        } else {
            ones = false;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] - '0' > 0 && s[i] != s[0]) {
                    l = s[i] - '0';
                    break;
                }
            }
        }
        
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] - '0' == l) {
                if (ones) s[i] = '1';
                else s[i] = '0';
            }
        }
        
        int a = stoi(s);
        int b = stoi(upper);
        
        //cout << a << endl;
        //cout << b << endl;
        
        return b - a;
    }
};
