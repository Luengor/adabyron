#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

bool palabra_valida(const string &w1, const string &w2)
{
    // La primera y última letras son iguales
    if (w1[0] != w2[0] || w1[w1.size() - 1] != w2[w2.size() - 1])
        return false;

    // Tienen las mismas letras 
    string sorted_w1 = w1;
    string sorted_w2 = w2;
    sort(sorted_w1.begin(), sorted_w1.end());
    sort(sorted_w2.begin(), sorted_w2.end());
    if (sorted_w1 != sorted_w2)
        return false;

    return true;
}

void casoDePrueba()
{
    // diccionario
    // igual hay letras de más?
    vector<vector<string>> diccionario(20, vector<string>());
    string line;

    string word;
    cin >> word;
    while (word != ".")
    {
        diccionario[word.size()].push_back(word);
        cin >> word;
    }

    // vamos leyendo y haciendo cosas
    cin >> word;
    while (word != ".")
    {
        // encontramos la palabra con menos distancia
        int len = word.size();
        auto &dicc = diccionario[len];

        if (dicc.size() == 0)
        {
            cout << word << ' ';
            cin >> word;
            continue;
        }
        

        bool found = palabra_valida(word, dicc[0]);
        int foundword = 0;
        for (int i = 1; i < dicc.size(); i++)
        {
            if (palabra_valida(word, dicc[i]))
            {
                if (!found)
                {
                    found = true;
                    foundword = i;
                }
                else
                {
                    found = false;
                    break;
                }
            }
        }

        if (found)
            cout << dicc[foundword] << ' ';
        else
            cout << word << ' ';

        cin >> word;
    }

    cout << ".\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i)
    {
        casoDePrueba();
    }

    return 0;
}

