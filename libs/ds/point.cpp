#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point() : x(0), y(0) {}
    point(int x, int y) : x(x), y(y) {}

    bool operator==(const point &p) const { return x == p.x && y == p.y; }

    // bool operator==(const point &p) const { return (fabs(x - p.x) < EPS) &&
    // (fabs(y - p.y) < EPS); }

    point operator+(const point &p) const { return point(x + p.x, y + p.y); }
    point operator-(const point &p) const { return point(x - p.x, y - p.y); }
    point operator*(int k) const { return point(x * k, y * k); }
    point operator/(int k) const { return point(x / k, y / k); }

    bool operator<(const point &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }

    double dist(const point &p) const { return hypot(x - p.x, y - p.y); }
};

int dot(point a, point b) { return a.x * b.x + a.y * b.y; }
int norm(point a) { return dot(a, a); }
double abs(point a) { return sqrt(norm(a)); }
double proj(point a, point b) { return dot(a, b) / abs(b); }
double angle(point a, point b) { return acos(dot(a, b) / abs(a) / abs(b)); }
int cross(point a, point b) { return a.x * b.y - a.y * b.x; }

point lines_intersect(point a1, point d1, point a2, point d2) {
    return a1 + d1 * (cross(a2 - a1, d2) / cross(d1, d2));
}
