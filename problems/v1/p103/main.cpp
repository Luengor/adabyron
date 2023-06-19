#include <stdint.h>
#include <math.h>
#include "fastio.h"

int *poly;
int degree;

double poly_at(double x);

bool testcase()
{
    // Read everything
    degree = fio_parse_int();
    if (degree == 20)
        return 0;

    for (int i = degree; i >= 0; i--)
        poly[i] = fio_parse_int();

    int blocks = fio_parse_int();

    // Evaluate 
    double v, total = 0, blocks1 = 1. / blocks;
    for (int i = 0; i < blocks; i++)
    {
        v = poly_at(i * blocks1);
        if (v > 0)
            total += (v > 1 ? 1 : v) * blocks1;
    }

    if (total > 0.501)
        fio_print("CAIN\n", 5);
    else if (total < 0.499)
        fio_print("ABEL\n", 5);
    else
        fio_print("JUSTO\n", 6);
    
    return 1;
}

int main(void)
{
    poly = new int[21];

    while (testcase());

    delete[] poly;


    return 0;
}

double poly_at(double x)
{
    double v = poly[0];
    double xx = x;

    for (int i = 1; i <= degree; i++, xx *= x)
        v += xx * poly[i];

    return v;
}

