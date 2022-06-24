#include <bits/stdc++.h>
using namespace std;

int add_digits(const string& s) {
    int digits = 0;
            
    for (int i = 0; i < s.size(); ++i) {
        digits += (s[i] - '0');
    }
    
    if (digits >= 10) {
        return add_digits(to_string(digits));
    }
    
    return digits;
}

int main() {
    int T; cin >> T;
    
    int t = 0;
    
    while (t < T) {
        ++t;
        
        cout << "Case #" << t << ": ";
        
        string s; cin >> s;
        int digits = add_digits(s);
        
        int x = 9 - digits;
        string xs = to_string(x);
        bool should_continue = false;
        
        int k = 0;
        while (k < s.size()) {
            if (x < (s[k] - '0')) {
                if (k == 0 && x == 0) {
                    ++k;
                    continue;
                }
                should_continue = true;
                cout << s.substr(0, k) + xs + s.substr(k) << endl;
                break;
            }
            ++k;
        }
        
        if (should_continue) {
            continue;
        }
        
        cout << s + xs << endl;
    }
}
