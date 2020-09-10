#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int l, c, lq, cq, quad, soma = 0;

  cin >> l >> c;

  int matriz[l][c];

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> matriz[i][j];
    }
  }
  cin >> lq >> cq >> quad;

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (quad == 1)
      {
        if (i < lq and j < cq)
        {
          soma += matriz[i][j];
        }
      }
      else if (quad == 2)
      {
        if (i < lq and j > cq)
        {
          soma += matriz[i][j];
        }
      }
      else if (quad == 3)
      {
        if (i > lq and j < cq)
        {
          soma += matriz[i][j];
        }
      }
      else if (quad == 4)
      {
        if (i > lq and j > cq)
        {
          soma += matriz[i][j];
        }
      }
    }
  }
  cout << soma;

  return 0;
}