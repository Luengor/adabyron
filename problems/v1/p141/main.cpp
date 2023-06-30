#include <stdint.h>
#include <stdio.h>
#include "fastio.h"
#include <stack>

using namespace std;

char braces[] = {'(', ')', '[', ']', '{', '}'};

// EOF is nono
bool testcase()
{
    // Check end
    char c;
    bool fail = false;
    if ((c = getchar_unlocked()) == EOF)
        return false;

    // a stack!
    stack<char> charstack;

    // Fill doing things
    do
    {
        if (fail)
        {
            c = getchar_unlocked();
            continue;
        }

        for (int i = 0; i < sizeof(braces); i += 2)
        {
            if (c == braces[i])
            {
                charstack.push(braces[i + 1]);
                break;
            }
            else if (c == braces[i + 1])
            {
                if (charstack.empty() || charstack.top() != braces[i + 1])
                    fail = true;
                else
                    charstack.pop();
                break;
            }
        }

        c = getchar_unlocked();
    } while (c != '\n' && c != EOF);

    if (fail || !charstack.empty())
        fio_print("NO\n", 3);
    else
        fio_print("YES\n", 4);

    return c != EOF;
    
}

int main(void)
{
    while (testcase());
    return 0;
}
