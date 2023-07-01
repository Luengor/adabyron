#include <stdint.h>
#include <vector>

#include "fastio.h"

bool testcase(void)
{
    // Read things
    int childs = fio_parse_int();
    int skip = fio_parse_int();

    if (!childs && !skip)
        return false;

    // Calculation moment
    int *child_v = new int[childs]();
    for (int i = 0; i < childs; i++)
        child_v[i] = (i + 1) % childs;

    int i, pi, s, l;
    for (i = 0, pi = i, s = skip, l = childs; l > 1;)
    {
        if (!s)
        {
            //printf("d%d ", i + 1);

            l--;
            //printf("(%d %d) ", pi + 1, i + 1);
            child_v[pi] = child_v[i];
            pi = i;
            i = child_v[i];
            s = skip;
        }
        else
        {
            //printf("s%d ", i + 1);
            s--;
            pi = i;
            i = child_v[i];
        }
    }

    printf("%d\n", i + 1);

    delete[] child_v;

    return true;
}

int main(void)
{
    while (testcase());

    return 0;
}
