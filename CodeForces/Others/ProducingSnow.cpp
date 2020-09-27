#include <iostream>
#include <Vector>
#include <algorithm>


using namespace std;


int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> S(n);
    vector<int> T(n);

    for (int i = 0; i < n;++i) {
        int s; cin >> s;
        S[i] = s;
    }

    vector<int> P(n+1);
    P[0] = 0;

    for (int i = 0;i < n;++i) {
        int t; cin >> t;
        T[i] = t;
        P[i+1] = P[i] + t;
    }
    vector<int> V(n+1);
    vector<int> L(n+1);

    for (int i = 0; i < n;++i) {
        int j = lower_bound(P.begin(), P.end(), S[i] + P[i]) - P.begin();
        if (j <= 0) continue;
        int rem = S[i] + P[i] - P[j-1];
        L[i] += 1;
        L[j-1] += -1;
        V[j-1] += rem;
    }

    for (int i = 1; i < n + 1;++i) {
        L[i] = L[i-1] + L[i];
    }


    for (int i = 0; i < n;++i) {
        cout << L[i] * T[i] + V[i] << " ";
    }

    return 0;
}