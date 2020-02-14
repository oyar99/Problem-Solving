#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    
    unordered_set<char> S;
    
    for (int i = 0; i < s.size(); ++i) S.insert(s[i]);
    
    string ans;
    
    if (S.size() & 1) ans = "IGNORE HIM!";
    else ans = "CHAT WITH HER!";
    
    cout << ans << endl;
}
