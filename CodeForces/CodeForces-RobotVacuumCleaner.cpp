#pragma GCC Optimize("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

bool compare(const string& a,  const string& b) {
    int sa = 0;
    int ha = 0;
    for (int i = 0;i < a.size();++i) {
        if (a[i] == 's') ++sa;
        else ++ha;
    }
    int sb = 0;
    int hb = 0;
    for (int i = 0; i < b.size();++i) {
        if (b[i] == 's') ++sb;
        else ++hb;
    }
    
    return hb * sa > ha * sb;
}
#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n;++i) {
        string s; cin >> s;
        S[i] = s;
    }

    sort(S.begin(), S.end(), compare);

    string f = "";
    for (int i = 0; i < n;++i) {
        f += S[i];
    }
    

    vector<int> P(f.size());
    P[0] = f[0] == 's' ? 1:0;
    for (int i = 1; i < f.size();++i) {
        P[i] = P[i-1] + (f[i] == 's' ? 1:0); 
    }
    int count = 0;
    for (int i = 0; i < f.size();++i) {
        if (f[i] == 'h') count += P[i];
    }

    cout << count << endl;
    
    return 0;
}