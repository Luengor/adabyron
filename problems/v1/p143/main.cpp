#include <stdint.h>
#include <vector>
#include "fastio.h"

using namespace std;

bool testcase(void)
{
    // Read pancakes
    vector<int> pancakes;
    int pancake = fio_parse_int();

    while (pancake != -1)
    {
        pancakes.push_back(pancake);
        pancake = fio_parse_int();
    }

    if (pancakes.size() == 0)
        return false;

    // Read moves
    int move_count = fio_parse_int();
    vector<int> moves;
    int move;

    for (int i = 0; i < move_count; i++)
    {
        move = fio_parse_int();

        if (moves.size() > 0 && moves[moves.size() - 1] == move)
            moves.pop_back();
        else
            moves.push_back(move);
    }

    // Move pancakes
    for (vector<int>::iterator m = moves.begin(); m != moves.end(); m++) 
    {
        vector<int>::iterator i1 = next(pancakes.begin(), pancakes.size() - *m);
        vector<int>::iterator i2 = pancakes.end() - 1;

        for (;i1 < i2; i1++, i2--)
        {
            int tmp = *i1;
            *i1 = *i2;
            *i2 = tmp;
        }
    }

    printf("%d\n", pancakes[pancakes.size() - 1]);

    return true;
}

int main(void)
{
    while (testcase());

    return 0;
}
