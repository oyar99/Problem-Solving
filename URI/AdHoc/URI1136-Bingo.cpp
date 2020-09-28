#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, B;

    while (true) {
        cin >> N >> B;

        if (N == 0 and B == 0) break;

        vector<int> A(N+1, 0);

        for (int i = 0; i < B;++i) {
            int b; cin >> b;
            A[b] = 1;
        }
        bool possible = true;
        for (int i = 0; i <= N;++i) {
            if (A[i]) continue;
            bool found = false;
            for (int j = N - i, k = N; j >= 0; --j, --k) {
                found = A[j] and A[k];
                if (found) break;
            }

            possible = found;

            if (i == 0) possible = false;

            if (!possible) break;
        }

        if (possible) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
