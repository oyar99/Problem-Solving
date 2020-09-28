#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

unordered_set<string> visited;

void generate_subsequences(string& text, set<string>& subs, int i, string s) {
    if (visited.count(s) > 0) return;
    if (i >= text.size()) return;
    subs.insert(s + text[i]);
    subs.insert(s);
    generate_subsequences(text, subs, i + 1, s + text[i]);
    generate_subsequences(text, subs, i + 1, s);
    visited.insert(s);
}

int main() {
    string text;
    while (getline(cin, text)) {
        set<string> subsequences;
        generate_subsequences(text, subsequences, 0, "");
        subsequences.erase("");
        for (const string& subsequence: subsequences) cout << subsequence << endl;
        cout << endl;
        visited.clear();
    }
    return 0;
}