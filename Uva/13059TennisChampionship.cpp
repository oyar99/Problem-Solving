#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll P;

    while (cin >> P) {

        ll count = 0;

        while (P > 1) {
            count += P >> 1;
            
            if (P & 1) P = (P + 1) >> 1;
            else P = P >> 1;
        }

        cout << count << endl;
    }
}
