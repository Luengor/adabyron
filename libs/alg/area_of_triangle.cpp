#include "../ds/point.cpp"
using namespace std;

int signed_area_parallelogram(point p1, point p2, point p3) {
    return cross(p2 - p1, p3 - p2);
}

double triangle_area(point p1, point p2, point p3) {
    return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}

bool clockwise(point p1, point p2, point p3) {
    return signed_area_parallelogram(p1, p2, p3) < 0;
}

bool counter_clockwise(point p1, point p2, point p3) {
    return signed_area_parallelogram(p1, p2, p3) > 0;
}