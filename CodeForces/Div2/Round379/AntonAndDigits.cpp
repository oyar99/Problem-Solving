#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<int, int> D;
    int twos; cin >> twos;
    D[2] = twos;
    int threes; cin >> threes;
    D[3] = threes;
    int fives; cin >> fives;
    D[5] = fives;
    int sixs; cin >> sixs;
    D[6] = sixs;
    int sum = 0;
    int l = min(min(D[2], D[5]), D[6]);
    D[2] -= l;
    D[5] -= l;
    D[6] -= l;
    sum += l * 256;
    int s = min(D[3], D[2]);
    D[3] -= s;
    D[2] -= s;
    sum += s * 32;
    cout << sum << endl;
    return 0;
}