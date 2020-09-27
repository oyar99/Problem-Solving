#include <bits/stdc++.h>

#define INF 10e8

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    int k = 0;

    string t = "";

    do {
        bool is_palindrome = true;

        for (int i = k, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                is_palindrome = false;
                break;
            }
        }

        if (is_palindrome) break;

        t.push_back(s[k]);
        ++k;

    } while (k < s.size());
    
    reverse(t.begin(), t.end());

    s += t;

    cout << s << endl;

}
