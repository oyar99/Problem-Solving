#pragma GCC Optimize("03")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    vector<int> F(n);
    for (int i = 0; i < n; ++i) {
        int e; cin >> e;
        F[i] = e;
    }
    vector<pair<int, int>> S(m);
    for (int i = 0; i < m;++i) {
        int e; cin >> e;
        S[i] = {i + 1, e};
    }

    sort(F.begin(), F.end());
    sort(S.begin(), S.end(), compare);
    vector<pair<int, int>> M(m + n);

    for (int i = 0, j = 0; i + j < m + n;) {
        if (i >= F.size()) {
            M[j+i] = S[j];
            ++j;
        }
        else if (j >= S.size()) {
            M[i+j] = {-1, F[i]};
            ++i;
        }
        else if (F[i] <= S[j].second) {
            M[i+j] = {-1, F[i]};
            ++i;
        }
        else {
            M[i+j] = S[j];
            ++j;
        }
    }
    vector<int> L;
    for (int i = 0, j = 0; i < m + n;++j) {
        int p = lower_bound(M.begin() + i, M.end(), make_pair(-1,j), compare) - M.begin();
        for (int s = p; s < p + k && s < m + n; ++s) {
            L.push_back(M[s].first);
        }
        i = p + k;
    }

    int count = 0;
    int si = 0;
    for (int i = 0; i < L.size();++i) {
        if (L[i] == -1) ++count;
        else ++si;
    }

    if (count != n) {
        cout << -1 << endl;
    } else {
        cout << si << endl;
        for (int i = 0; i < L.size();++i) {
            if (L[i] != -1) cout << L[i] << " ";
        }
    }

    
    return 0;
}