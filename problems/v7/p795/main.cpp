#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool casoDePrueba()
{
    char c;
    int col, li;
    cin >> col >> li;

    if (li == 0 && col == 0)
        return false;

    cin >> c;

    // leer tabla 
    vector<string> lines;
    for (int i = 0; i < li +2; i++)
    {
        std::string line;
        getline(cin, line);
        lines.push_back(line);
    }


    /// imprimir tabla
    for (int l = -1; l <= col; l++)
    {
        for (int c = -1; c <= li; c++)
        {
            if (l == -1 || l == col)
                cout << '-';
            else if (c == -1 || c == li)
                cout << '|';
            else
            {
                cout << lines[c+1][(col - l - 1)+1];
            }
        }

        cout << endl;
    }


    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());
  
    return 0;
}

