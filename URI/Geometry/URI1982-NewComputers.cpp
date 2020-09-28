#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <cmath>
#include <cstdio>
#define int long long

struct Point {
	double x;
	double y;

	Point(double x, double y):x(x),y(y){}

};

bool operator <(const Point& a,const Point& b) {
	if (a.x >= 0 && b.x < 0) return true;
	if (a.x < 0 && b.x >= 0) return false;
	if (a.x == 0 && b.x == 0) {
		if (a.y >= 0 || b.y >= 0)
			return a.y > b.y;
		return b.y > a.y;
	}

	int det = (a.x) * (b.y) - (b.x) * (a.y);
	if (det < 0)
		return true;
	if (det > 0)
		return false;

	int d1 = (a.x) * (a.x) + (a.y) * (a.y);
	int d2 = (b.x) * (b.x) + (b.y) * (b.y);
	return d1 > d2;
}

double get_area(Point a, Point b, Point c) {
	double ab = std::sqrt(std::pow((a.x - b.x), 2) + std::pow((a.y - b.y), 2));
	double bc = std::sqrt(std::pow((b.x - c.x), 2) + std::pow((b.y - c.y), 2));
	double ca = std::sqrt(std::pow((c.x - a.x), 2) + std::pow((c.y - a.y), 2));
	double s = (ab + bc + ca) / 2;
	return std::sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

int get_distance_from_line(Point a, Point b, Point c) {
	return std::abs((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x));
}

int get_side(Point a, Point b, Point c) {
	int value = (c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x);
	return value == 0 ? 0 : value < 0 ? -1 : 1;
}

void quick_hull(std::vector<Point>& points, Point min, Point max, int side, std::set<Point>& out_hull) {
	int max_distance = 0;
	Point p = { 0,0 };
	bool found = false;

	for (int i = 0; i < points.size(); ++i) {
		if (get_side(min, max, points[i]) == side) {
			int dist = get_distance_from_line(min, max, points[i]);
			if (dist > max_distance) {
				max_distance = dist;
				p = points[i];
				found = true;
			}
		}
	}

	if (!found) {
		out_hull.insert(min);
		out_hull.insert(max);
	}
	else {
		int side1 = get_side(p, min, max);
		int side2 = get_side(p, max, min);
		quick_hull(points, p, min, -side1, out_hull);
		quick_hull(points, p, max, -side2, out_hull);
	}
}

std::set<Point> convex_hull(std::vector<Point>& points) {
	Point min_x = points[0];
	Point max_x = points[0];

	for (int i = 0; i < points.size();++i) {
		if (points[i].x < min_x.x)
			min_x = points[i];
		if (points[i].x > max_x.x)
			max_x = points[i];
	}

	std::set<Point> hull;

	quick_hull(points, min_x, max_x, 1, hull);
	quick_hull(points, min_x, max_x, -1, hull);

	return hull;

}


#undef int
int main()
{
#define int long long
	int N;
	while (true) {
        std::cin >> N;

        if (N == 0) break;

		std::vector<Point> points;
        double p_x = 0.0;
        double p_y = 0.0;
		for (int i = 0; i < N;++i) {
			double x, y;
			std::cin >> x >> y;
            p_x += x;
            p_y += y;
			Point p = {x,y};
			points.push_back(p);
		}
        p_x /= N;
        p_y /= N;

        for (int i = 0; i < N;++i) {
            points[i].x -= p_x;
            points[i].y -= p_y;
        }
		std::set<Point> hull = convex_hull(points);
		std::vector<Point> hull_v;
		for (auto p : hull) {
			hull_v.push_back(p);
		}

        double per = 0;
        for (int i = 0; i < hull_v.size();++i) {
            double dist = std::sqrt(std::pow((hull_v[(i+1) % hull_v.size()].y - hull_v[i].y), 2) + std::pow((hull_v[(i+1) % hull_v.size()].x - hull_v[i].x), 2));
            per += dist;
        }
		printf("Tera que comprar uma fita de tamanho %.2f.\n", per - 0.0005);
    }
}
