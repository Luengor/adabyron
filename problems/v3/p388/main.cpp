#include <stdint.h>
#include "fastio.h"

#define aabs(x) ((x) > 0 ? (x) : -(x))

class Point 
{
    public:
        int x, y;
        Point()
        {
            x = 0;
            y = 0;
        };

        void read()
        {
            x = fio_parse_int();
            y = fio_parse_int();
        }

        int distance(Point other)
        {
            return aabs(this->x - other.x) + aabs(this->y - other.y);
        }
};

Point *points;
int point_count;
#define maxpoints 1000

bool testcase(void)
{
    point_count = fio_parse_int();

    if (!point_count)
        return false;

    for (int i = 0; i < point_count; i++)
        points[i].read();

    // Get the largest distance
    int maxdis = 0, dis;
    for (int i = 0; i < point_count; i++)
        for (int j = i + 1; j < point_count; j++)
        {
            dis = points[i].distance(points[j]);
            maxdis = (dis > maxdis ? dis : maxdis);
        }

    printf("%d\n", maxdis);
    return true;
}

int main(void)
{
    points = new Point[maxpoints];
    
    while (testcase());

    delete[] points;

    return 0;
}
