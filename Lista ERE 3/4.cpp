#include <iostream>
using namespace std;

struct ponto
{
    int x, y;
};

struct retangulo
{
    ponto vert1;
    ponto vert2;
};

int analisa(struct retangulo retangulo[], struct ponto ponto, int quant)
{

    int correto = 0;

    for (int i = 0; i < quant; i++)
        if (ponto.x >= retangulo[i].vert1.x and ponto.y >= retangulo[i].vert1.y)
        {
            if (ponto.x <= retangulo[i].vert2.x and ponto.y <= retangulo[i].vert2.y)
            {
                correto++;
            }
        }
    cout << correto;
}

int main()
{
    ponto ponto;

    cin >> ponto.x >> ponto.y;

    int quant;

    cin >> quant;

    retangulo retangulo[quant];
    for (int J = 0; J < quant; J++)
    {
        cin >> retangulo[J].vert1.x >> retangulo[J].vert1.y >> retangulo[J].vert2.x >> retangulo[J].vert2.y;
    }
    analisa(retangulo, ponto, quant);

    return 0;
}
