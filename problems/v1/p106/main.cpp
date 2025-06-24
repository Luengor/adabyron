#include <stdint.h>
#include "fastio.h"

char number[13];

bool testcase()
{
    number[0] = fio_get_char();
    if (number[0] == '0') return false;

    int i;
    for (i = 1; i < 13; i++)
        if ((number[i] = fio_get_char()) == '\n')
        {
            break;
        }

    int v = 0;

    for (int j = 1; i - 1 - j >= 0; j++)
        v += (number[i - 1 - j] - '0') * (j % 2 == 0 ? 1 : 3); 

    if (((number[i - 1] - '0') + v) % 10 != 0)
    {
        printf("NO\n");
        return true;
    }

    printf("SI ");

    if (i != 8)
    {

    }

    return true;
}

int main(void)
{
    while (testcase());
    return 0;
}
