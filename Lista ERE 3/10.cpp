#include <iostream>
#include <cmath>
using namespace std;

struct cliente
{
  string nome;
  int x, y, distancia;
  float valor;
};

int ordena(int distancia[], struct cliente cliente[], int totalCliente, int atender)
{
  int valor_pivo, j;
  float soma = 0;
  for (int i = 1; i < totalCliente; i++)
  {
    valor_pivo = distancia[i];
    j = i - 1;
    while ((j >= 0) and (valor_pivo < distancia[j]))
    {
      distancia[j + 1] = distancia[j];
      j--;
    }
    distancia[j + 1] = valor_pivo;
  }

  for (int k = 0; k < atender; k++)
  {
    for (int t = 0; t < totalCliente; t++)
    {
      if (distancia[k] == cliente[t].distancia)
      {
        soma += cliente[t].valor;
      }
    }
  }
  cout << soma;
}

int main()
{

  int atender, xPizza, yPizza, totalCliente;

  cin >> atender >> xPizza >> yPizza >> totalCliente;

  int distancia[totalCliente];

  cliente cliente[totalCliente];

  for (int i = 0; i < totalCliente; i++)
  {
    cin >> cliente[i].nome >> cliente[i].x >> cliente[i].y >> cliente[i].valor;
    cliente[i].distancia = sqrt((xPizza - cliente[i].x) * (xPizza - cliente[i].x) + (yPizza - cliente[i].y) * (yPizza - cliente[i].y));
    distancia[i] = cliente[i].distancia;
  }

  ordena(distancia, cliente, totalCliente, atender);

  return 0;
}