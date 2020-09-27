#include <bits/stdc++.h>

using namespace std;

char get_char(char& c, char& f) {
    if ((c == 'a' && f == 'b') || (c == 'b' && f == 'a') || (c == 'b' && f == 'b') || (c == 'a' && f == 'a')) return 'c';
    if ((c == 'b' && f == 'c') || (c == 'c' && f == 'b') || (c == 'b' && f == 'b') || (c == 'c' && f == 'c')) return 'a';
    if ((c == 'c' && f == 'a') || (c == 'a' && f == 'c') || (c == 'c' && f == 'c') || (c == 'a' && f == 'a')) return 'b';
    if (c == '?' && f == '?') return 'a';
    if ((c == '?' && f == 'a') || (f == '?' && c == 'a')) return 'b';
    if ((c == '?' && f == 'b') || (f == '?' && c == 'b')) return 'c';
    if ((c == '?' && f == 'c') || (f == '?' && c == 'c')) return 'a'; 
}

bool solve(string& s) {
    if (s.size() == 1) {
        if (s[0] == '?') s[0] = 'a';
        return true;
    }
    if (s[0] == '?') s[0] = get_char(s[1],s[0]);
    for (int i = 1; i < s.size() - 1; ++i) {
        if (s[i] == '?') s[i] = get_char(s[i-1], s[i+1]);
        if (s[i] == s[i-1]) return false;
    }
    if (s[s.size() - 1] == '?') s[s.size() - 1] = get_char(s[s.size() - 2], s[s.size() - 1]);
    if (s[s.size() - 1] == s[s.size() - 2]) return false;
    return true;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T;++t) {
        string s; cin >> s;
        if (solve(s)) cout << s << endl;
        else cout << -1 << endl;
    }
}