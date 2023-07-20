#include <stdint.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "fastio.h"

using namespace std;


string readname()
{
    string s = "";
    char c;
    while ((c = getc_unlocked(stdin)) != '\n')
        s += c;

    return s;
}

bool testcase(void)
{
    // Get ejs
    int ejs = fio_parse_int();

    if (ejs == 0)
        return false;

    // Get things
    map<string, int> students;

    for (int i = 0; i < ejs; i++)
    {
        string name = readname();
        string valid = readname();
        int delta = valid[0] == 'I' ?  -1 : 1;

        if (students.find(name) != students.end())
            students[name] += delta;
        else
            students[name] = delta;
    }

    //// Print things
    for (auto i = students.begin(); i != students.end(); i++)
    {
        if (i->second != 0)
            printf("%s, %d\n", i->first.c_str(), i->second);
    }
    fio_print("---\n", 4);

    return true;
}

int main(void)
{
    while (testcase());

    return 0;
}
