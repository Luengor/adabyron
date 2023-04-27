#include "fastio.h"

int main(void)
{
    int n;
    for (n = fio_parse_int(); n > 0; n--)
        fio_print("Hola mundo.\n", 12);
}
