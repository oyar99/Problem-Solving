#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

int main() {
    string t; cin >> t;
    int upper_chars = 0;

    for (const char& c: t) if (isupper(c)) ++upper_chars;

    if (upper_chars > t.size() - upper_chars) for (char& c: t) c = toupper(c);
    else for (char& c: t) c = tolower(c);

    cout << t << endl;

    return 0;
}