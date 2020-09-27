#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define int long long

using namespace std;

#undef int
int main() {
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;

    for (int t = 0; t < T;++t) {
        int n; cin >> n;

        vector<int> A(n);
        vector<int> B(n);

        for (int i = 0; i < n;++i) {
            int e; cin >> e;
            A[i] = e;
        }

        for (int i = 0; i < n;++i) {
            int e; cin >> e;
            B[i] = e;
        }

        bool change = false;
        bool done = false;
        bool no = false;
        int dif = 0;
        for (int i = 0; i < n;++i) {
            if (change) {
                if (B[i] - A[i] == 0) {
                    done = true;
                    change = false;
                } else if (B[i] - A[i] != dif) {
                    cout << "NO" << endl;
                    no = true;
                    break;
                }
            } else {
                if (done) {
                    if (B[i] - A[i] != 0) {
                        cout << "NO" << endl;
                        no = true;
                        break;
                    }
                } else {
                    if (B[i] - A[i] > 0) {
                        dif = B[i] - A[i];
                        change = true;
                    } else if (B[i] - A[i] < 0) {
                        cout << "NO" << endl;
                        no = true;
                        break;
                    }
                }
            }
        }

        if (!no) cout << "YES" << endl;
    }

    return 0;
}