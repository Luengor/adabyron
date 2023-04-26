#include "fastio.h"

void testcase(void)
{
    int year = fio_parse_int();

    if (year % 100 == 0) 
        printf("%d\n", year / 100);
    else
        printf("%d\n", year / 100 + 1);
}

int main(void)
{
    int tests;

    for (tests = fio_parse_int(); tests > 0; tests--)
        testcase();

    return 0;
}

