#include <stdio.h>

int testcase(void)
{
    int h, m;

    scanf("%d:%d\n", &h, &m);

    if (h == 0 && m == 0)
        return 0;

    printf("%d\n", (23 - h) * 60 + (60 - m));
    return 1;
}

int main(void)
{
    while (testcase());

    return 0;
}
