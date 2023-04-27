#include <stdint.h>
#include "fastio.h"
#include <math.h>

void testcase(void)
{
    long long v = fio_parse_int(), n;
    int i;
    for (i = 0, n = 1; n < v; i++, n=n<<1);
    printf("%d\n", i);
}

int main(void)
{
    int tests;

    for (tests = fio_parse_int(); tests > 0; tests--)
        testcase();

    return 0;
}
