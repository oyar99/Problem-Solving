#include <bits/stdc++.h>

#define INF 10e8

using namespace std;

typedef long long ll;

struct Point {
    int x;
    int y;

    Point(int x, int y):x(x),y(y) {}

};

struct Line {
    Point a;
    Point b;
};

double distance_to_line(Line& l, Point& p) {
    double A = p.x - l.a.x;
    double B = p.y - l.a.y;
    double C = l.b.x - l.a.x;
    double D = l.b.y - l.a.y;

    double dot = A * C + B * D;
    double len = C * C + D * D;

    double param = dot / len;

    double xx, yy;

    if (param < 0) {
        xx = l.a.x;
        yy = l.a.y;
    } else if (param > 1) {
        xx = l.b.x;
        yy = l.b.y;
    } else {
        xx = l.a.x + param * C;
        yy = l.a.y + param * D;
    }

    double dx = p.x - xx;
    double dy = p.y - yy;

    return sqrt(dx * dx + dy * dy);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y; cin >> x >> y;
    int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;

    Point p = {x, y};

    Line AB = {Point(ax, ay), Point(ax, by)};
    Line BC = {Point(ax, by), Point(bx, by)};
    Line CD = {Point(bx, by), Point(bx, ay)};
    Line DA = {Point(bx, ay), Point(ax, ay)};

    double ans = min({distance_to_line(AB, p), distance_to_line(BC, p), distance_to_line(CD, p), distance_to_line(DA, p)});
    
    printf("%.3f\n", ans);
}
