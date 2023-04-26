#include <stdint.h>
#include "fastio.h"

void testcase(void)
{
    int16_t n = fio_parse_int(); 

    if (n % 2 == 0)
        printf("%d\n", n + 1);
    else
        printf("%d\n", n - 1);
}

int main(void)
{
    int tests;

    for (tests = fio_parse_int(); tests > 0; tests--)
        testcase();

    return 0;
}
