#include <stdint.h>
#include "fastio.h"

void testcase(void)
{
    int d1, d2, tmp;
    d1 = fio_parse_int();
    d2 = tmp = fio_parse_int();

    if (d2 < d1)
    {
        d2 = d1;
        d1 = tmp;
    }

    printf("%d", d1 + 1);
    for (int i = d1 + 2; i <= d2 + 1; i++)
        printf(" %d", i);

    printf("\n");
}

int main(void)
{
    int tests;

    for (tests = fio_parse_int(); tests > 0; tests--)
        testcase();

    return 0;
}
