#include <stdint.h>
#include <stdio.h>

bool testcase(void)
{
    char c = getchar_unlocked();
    int n = 0;

    if (c == '-')
        return false;

    putchar_unlocked(c);
    n += c - '0';

    while ((c = getchar_unlocked()) != '\n')
    {
        printf(" + %c", c);
        n += c - '0';
    }

    printf(" = %d\n", n);

    return true;
}

int main(void)
{
    while (testcase());

    return 0;
}
