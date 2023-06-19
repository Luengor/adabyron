#include <stdint.h>
#include "fastio.h"

void testcase(void)
{
    int pisovivo = fio_parse_int();
    int escalonespiso = fio_parse_int();
    int pisobajar = fio_parse_int();
    int escalonesbajar = fio_parse_int();

    escalonesbajar += pisobajar * escalonespiso;

    printf("%d %d\n", escalonesbajar, pisovivo * escalonespiso + escalonesbajar);
}

int main(void)
{
    int tests;

    for (tests = fio_parse_int(); tests > 0; tests--)
        testcase();

    return 0;
}
