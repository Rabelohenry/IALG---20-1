#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    float matriz[4][4], valor = 0;
    int num;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> matriz[i][j];
        }
    }
    cin >> num;

    int itinerario[num];

    for (int k = 0; k < num; k++)
    {
        cin >> itinerario[k];
        if (k != 0)
        {
            valor += matriz[itinerario[k - 1]][itinerario[k]];
        }
    }

    cout << valor;

    return 0;
}