    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
        int n; cin >> n;
     
        for (int i = 0; i < n; ++i) {
            string y; cin >> y;
            string ans;
            int sum = 0;
            for (int i = 0; i < y.size();++i) sum += y[i] - '0';
     
            if (sum % 3) {
                ans = "cyan";
            } else {
                int zero = 0;
     
                for (int i = 0; i < y.size();++i) zero += (y[i] == '0' ? 1: 0);
     
                if (zero <= 0) {
                    ans = "cyan";
                } else if (zero > 1) {
                    ans = "red";
                } else {
                    bool even = false;
     
                    for (int i = 0; i < y.size();++i) {
                        if (y[i] == '0') continue;
                        
                        if (!((y[i] - '0') % 2)) {
                            even = true;
                            break;
                        }
                    }
     
                    if (even) ans = "red";
                    else ans = "cyan";
                }
            }
     
            cout << ans << endl;
        }
    }