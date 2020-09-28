#include <bits/stdc++.h>

#define EPS 10e-9

using namespace std;

double f(vector<pair<int, int>>& H, double x) {
    double d = 0;

    for (int i = 0; i < H.size(); ++i) {
        d = max(d, (H[i].first - x) * (H[i].first - x) + (H[i].second) * (H[i].second));
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X; cin >> N >> X;

    vector<pair<int, int>> H(N);

    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        H[i] = {x, y};
    }

    double l = 0;
    double r = X;


    while (l + EPS < r) {

        double lt = l + (r - l) / 3;
        double rt = r - (r - l) / 3;

        if (f(H, lt) > f(H, rt)) l = lt;
        else r = rt;
    }

    printf("%.2f %.2f\n", l, sqrt(f(H, l)));
}
