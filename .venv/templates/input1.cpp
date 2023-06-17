#include <stdint.h>
#include "fastio.h"

void testcase(void)
{

}

int main(void)
{
    int tests;

    for (tests = fio_parse_int(); tests > 0; tests--)
        testcase();

    return 0;
}
