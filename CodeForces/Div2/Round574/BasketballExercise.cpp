#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define int long long

int max_height(vector<int>& A, vector<int>& B, int n, int i, bool fromA, vector<vector<int>>& memo) {
    if (i >= n) return 0;

    if (memo[i][fromA] != INT32_MIN) return memo[i][fromA];

    if (fromA) {
        int ans = max(max_height(A, B, n, i + 1, fromA, memo), max_height(A, B, n, i + 1, !fromA, memo) + A[i]);
        memo[i][fromA] = ans;
        return ans;
    } else {
        int ans = max(max_height(A, B, n, i + 1, fromA, memo), max_height(A, B, n, i + 1, !fromA, memo) + B[i]);
        memo[i][fromA] = ans;
        return ans;
    }
}

#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n;++i) {
        int h; cin >> h;
        A[i] = h;
    }

    for (int i = 0; i < n;++i) {
        int h; cin >> h;
        B[i] = h;
    }
    vector<vector<int>> memo(n, vector<int>(2, INT32_MIN));
    cout << max(max_height(A, B, n, 0, true, memo), max_height(A, B, n, 0, false, memo)) << endl;

    return 0;
}