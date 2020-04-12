#define EPS 10e-9

#include <bits/stdc++.h>

using namespace std;

double get_area(vector<int>& V, double cut) {
    double area = 0;

    for (int i = 0; i < V.size(); ++i) {
        if (V[i] < cut) continue;
        area += V[i] - cut;
    }

    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n, a; cin >> n >> a;
        if (n == 0 && a == 0) break;
        vector<int> V(n);

        for (int i = 0; i < n; ++i) cin >> V[i];

        
        int s = 0;

        for (int i = 0; i < n; ++i) s += V[i];

        if (s == a) {
            printf(":D\n");
            continue;
        }

        if (a > s) {
            printf("-.-\n");
            continue;
        }

        double r = 0;

        for (int i = 0; i < n; ++i) r = max((int)r, V[i]);

        double l = 0;

        while (l + EPS < r) {
            double m = (l + r) / 2.f;

            double area = get_area(V, m);
            if (area < a) r = m;
            else l = m;
        }

        printf("%.4f\n", l);
    }

}
