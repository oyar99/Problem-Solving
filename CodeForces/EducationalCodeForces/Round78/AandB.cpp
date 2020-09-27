#include <bits/stdc++.h>

using namespace std;

bool check(int r, int d) {
    long long sum = r * (r + 1) / 2;

    if (sum < d) return false;

    return sum % 2 == d % 2;
}

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int a, b; cin >> a >> b;

        if (a > b) swap(a,b);

        if (b - a == 0) {
            cout << "0" << endl;
            continue;
        }

        int r = 1;
        while (!check(r, b - a)) ++r;

        cout << r << endl;
    }
}