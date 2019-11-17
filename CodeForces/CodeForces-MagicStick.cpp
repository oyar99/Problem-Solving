#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;

    for (int t = 0; t < T;++t) {
        int x, y; cin >> x >> y;

        if (x >= y) { 
            cout << "YES" << endl;
        }
        else {
            if (x <= 3) {
                if (x == 1) {
                    cout << "NO" << endl;
                }
                else {
                    if (y <= 3) cout << "YES" << endl;
                    else cout << "NO" << endl;
                }
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}