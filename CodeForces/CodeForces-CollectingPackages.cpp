#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int n; cin >> n;
        
        vector<Point> points(n);

        for (int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            points[i] = {x, y};
        }

        sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
            if (a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        });

        Point r = {0, 0};
        bool pos = true;
        string s = "";
        for (int i = 0; i < n; ++i) {
            if (points[i].x < r.x || points[i].y < r.y) {
                pos = false;
                break;
            }

            while (points[i].x > r.x) {
                s += "R";
                r.x += 1;
            }

            while (points[i].y > r.y) {
                s += "U";
                r.y += 1;
            }
        }

        if (!pos) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << s << endl;
        }
    }
}