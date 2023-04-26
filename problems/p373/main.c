#include "fastio.h"

void testcase(void)
{
    long long n, blocks;
    n = fio_parse_longlong();

    // 2n^2 + (n - 1) * 4 * (n - 2)
    // 6n^2 - 12n + 8
    blocks = (6 * (n * n) - 12 * n + 8);
    printf("%lld\n", blocks);
}

int main(void)
{
    int tests;

    for (tests = fio_parse_int();tests > 0; tests--)
        testcase();

    return 0;
}
