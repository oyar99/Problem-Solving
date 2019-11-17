#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    
    for (int t = 0; t < T;++t) {
        vector<int> candles(10);
        int min_candles = INT32_MAX;
        int candle = -1;
        for (int i = 0; i < 10;++i) {
            int c; cin >> c;
            candles[i] = c;

            if (i == 0) continue;

            if (c < min_candles) {
                min_candles = c;
                candle = i;
            }
        }

        bool found = false;
        if (candles[0] < min_candles) {
            string age = "1";
            for (int i = 0; i < candles[0] + 1;++i) {
                age += "0";
            }
            cout << age << endl;
            
        } else {
            string age = "";
            for (int i = 0; i < min_candles + 1;++i) {
                ostringstream ss;
                ss << candle;
                age += ss.str();
            }

            cout << age << endl;
        }

    }
    return 0;
}