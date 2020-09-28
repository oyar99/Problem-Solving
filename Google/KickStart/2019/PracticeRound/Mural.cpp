#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    
    for (int t = 0; t < T;++t) {
        
        int N; cin >> N;
        
        vector<int> W(N);
        string str; cin >> str;
        for (int i = 0; i < N;++i) W[i] = str[i] - '0';

        int k = ceil(N / 2.f);
        int s = 0;
        
        for (int i = 0; i < k; ++i) s+=W[i];
        
        int m = s;
        int l = s;
        for (int i = 1; i < N - k + 1; ++i) {
            l = l-W[i-1]+W[i+k-1];
            m = max(m, l);
        }
        cout << "Case #" << (t+1) << ": " << m << endl;
    }
}