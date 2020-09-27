#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

constexpr int t = 25;

bool change(unordered_map<int, int>& C, int m) {
    if (m == 0) {
        return true;
    }
    else if (m == 25) {
        if (C[25] > 0) {
            --C[25];
            return true;
        } else {
            return false;
        }
    } else if (m == 75) {
        if (C[50] > 0 && C[25] > 0) {
            --C[50];
            --C[25];
            return true;
        } else if (C[25] >= 3) {
            C[25] -= 3;
            return true;
        } else {
            return false;
        }
    }
}

bool solve(vector<int>& A) {
    unordered_map<int, int> C;
    C[25] = 0;
    C[50] = 0;
    C[100] = 0;

    for (int i = 0; i < A.size();++i) {
        int m = A[i] - t;
        C[A[i]] += 1;
        if (!change(C, m)) return false;
    }
    return true;
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n;++i) {
        int a; cin >> a;
        A[i] = a;
    }

    if (solve(A)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}