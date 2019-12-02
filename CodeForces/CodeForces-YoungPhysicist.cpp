#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;


struct vector3 {
    int x;
    int y; 
    int z;

    vector3():x(0),y(0),z(0){}
    vector3(int x, int y, int z):x(x),y(y),z(z) {}

    vector3 operator + (const vector3& other) {
        return vector3(x + other.x, y + other.y, z + other.z);
    } 
};

int main() {
    int n; cin >> n;
    vector3 body = vector3();
    for (int i = 0; i < n; ++i) {
        int x, y, z; cin >> x >> y >> z;
        body = body + vector3(x, y, z);
    }

    if (body.x == 0 && body.y == 0 && body.z == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}