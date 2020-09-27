#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> A(n);
    unordered_set<int> Aset;
    for (int i = 0; i < n;++i) {
        int e; cin >> e;
        A[i] = e;
        Aset.insert(e);
    }

    int m; cin >> m;
    vector<int> B(m);
    unordered_set<int> Bset;
    for (int i = 0; i < m;++i) {
        int e; cin >> e;
        B[i] = e;
        Bset.insert(e);
    }

    bool pos = false;
    int a, b;
    for (int i = 0; i < n;++i) {
        for (int j = 0; j < m;++j) {
            int sum = A[i] + B[j];

            if (Aset.count(sum) <= 0 && Bset.count(sum) <= 0) {pos = true; a = A[i]; b = B[j];break;}
        }
        if (pos) break;
    }

    cout << a << " " << b << endl;

    return 0;
}