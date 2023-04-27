#include "../../libs/fastio.h"

int main(void)
{
    int testcases;

    for (testcases = fio_parse_int(); testcases > 0; testcases--)
        printf("%d\n", fio_parse_int() / 100);

    return 0;
}

