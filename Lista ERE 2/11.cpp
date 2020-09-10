#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int l;

  cin >> l;

  float matriz[l][l], min, custo, preco = 0, total = 0;

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < l; j++)
    {
      cin >> matriz[i][j];
      total += matriz[i][j];
    }
  }
  cin >> min >> custo;

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < l; j++)
    {
      if (matriz[i][j] < min)
      {
        preco += min - matriz[i][j];
      }
    }
  }

  preco = preco * custo;

  cout << preco;

  return 0;
}