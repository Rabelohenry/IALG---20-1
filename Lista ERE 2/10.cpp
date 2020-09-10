#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int l, soma = 0;

  cin >> l;

  int matriz[l][l];

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < l; j++)
    {
      cin >> matriz[i][j];
      if (i != 0 and i != l - 1 and j < (l / 2) - 1 and j < i)
      {
        if (i < (l / 2) + 1)
        {
          soma += matriz[i][j];
        }
        else if (j < l - i - 1)
        {
          soma += matriz[i][j];
        }
      }
    }
  }

  cout << soma;

  return 0;
}