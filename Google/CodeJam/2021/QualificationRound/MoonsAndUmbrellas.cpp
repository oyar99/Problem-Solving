#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int x, y; cin >> x >> y;

        string s; cin >> s;

        if (s.size() <= 1) {
            cout << "Case #" << (t + 1) << ": 0" << endl;
            continue; 
        }

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '?') continue;

            if (i == 0) {
                if (s[i+1] == 'J') {
                    if (x < 0) s[i] = 'C';
                    else s[i] = 'J';
                } else if (s[i+1] == 'C') {
                    if (y < 0) s[i] = 'J';
                    else s[i] = 'C';
                } else {
                    if (x < 0 && x < y) s[i] = 'C';
                    else if (y < 0 && y < x) s[i] = 'J';
                    else {
                        char after = 'C';
                        for (int j = i + 2; j < s.size(); ++j) {
                            if (s[j] != '?') {
                                after = s[j];
                                break;
                            }
                        }

                        s[i] = after;
                    }
                }
            } else if (i == s.size() - 1) {
                if (s[i-1] == 'C') {
                    if (x < 0) s[i] = 'J';
                    else s[i] = 'C';
                } else if (s[i-1] == 'J') {
                    if (y < 0) s[i] = 'C';
                    else s[i] = 'J';
                }
            } else {
                if (s[i-1] == 'C' && s[i+1] == 'J') {
                    s[i] = 'C';
                } else if (s[i-1] == 'J' && s[i+1] == 'C') {
                    s[i] = 'C';
                } else if (s[i-1] == 'C' && s[i+1] == 'C') {
                    if (x + y < 0) s[i] = 'J';
                    else s[i] = 'C';
                } else if (s[i-1] == 'J' && s[i+1] == 'J') {
                    if (x + y < 0) s[i] = 'C';
                    else s[i] = 'J';
                } else if (s[i-1] == 'C' && s[i+1] == '?') {
                    if (x < 0) s[i] = 'J';
                    else s[i] = 'C';
                } else if (s[i-1] == 'J' && s[i+1] == '?') {
                    if (y < 0) s[i] = 'C';
                    else s[i] = 'J';
                }
            }
        }

        int count = 0;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == 'C' && s[i+1] == 'J') count += x;
            else if (s[i] == 'J' && s[i+1] == 'C') count += y;
        }


        cout << "Case #" << (t + 1) << ": " << count << endl;
    }
}
