#include <bits/stdc++.h>

using namespace std;

#define ll long long

int M [300][300];

struct cell {
    int i;
    int j;
    int v;
};

int main () {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int r, c; cin >> r >> c;

        auto cmp = [](cell & a, cell & b) {
            return a.v < b.v;
        };

        priority_queue<int, vector<cell>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> M[i][j];
                pq.push({i, j, M[i][j]});
            }
        }

        ll count = 0;

        while (!pq.empty()) {

            auto front = pq.top();
            pq.pop();
            int i = front.i;
            int j = front.j;
            int v = front.v;

            if (v != M[i][j]) {
                continue;
            }

            if (i-1>=0&&M[i][j]>M[i-1][j]+1) {
                count += (M[i][j]-M[i-1][j]-1);
                M[i-1][j] = M[i][j]-1;
                pq.push({i-1, j, M[i-1][j]});
            }

            if (i+1<r&&M[i][j]>M[i+1][j]+1) {
                count += (M[i][j]-M[i+1][j]-1);
                M[i+1][j] = M[i][j]-1;
                pq.push({i+1, j, M[i+1][j]});
            }

            if (j-1>=0&&M[i][j]>M[i][j-1]+1) {
                count += (M[i][j]-M[i][j-1]-1);
                M[i][j-1] = M[i][j]-1;
                pq.push({i, j-1, M[i][j-1]});
            }

            if (j+1<c&&M[i][j]>M[i][j+1]+1) {
                count += (M[i][j]-M[i][j+1]-1);
                M[i][j+1] = M[i][j]-1;
                pq.push({i, j+1, M[i][j+1]});
            }
        }

        cout << "Case #" << t + 1 << ": " <<  count << endl;
    }
}
