#include <bits/stdc++.h>

#define INF 10e17+5
    
using namespace std;

typedef long long ll;

struct Point {
    ll x;
    ll y;
    ll z;
};

ll distance(Point& a, Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    
    vector<Point> points(n);

    for (int i = 0; i < n; ++i) {
        ll x, y, z; cin >> x >> y >> z;
        points[i] = {x,y,z};
    }

    vector<bool> deleted(n);
    
    for (int i = 0; i < (n >> 1); ++i) {
        
        Point a;
        int j = -1;

        for (int i = 0; i < n; ++i) {
            if (!deleted[i]) {
                a = points[i];
                deleted[i] = true;
                j = i;
                break;
            }
        }

        ll dist = INF;
        int k = -1;

        for (int i = 0; i < n; ++i) {
            if (deleted[i]) continue;
            ll d = distance(a, points[i]);

            if (d < dist) {
                dist = d;
                k = i;
            }
        }
        assert(k >= 0);
        deleted[k] = true;
        cout << j + 1 << " " << k + 1 << endl;
    }
        
    return 0;
}
