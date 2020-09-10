#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int n, x, y, peao = 0;
  cin >> n;

  int matriz[n][n];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> matriz[i][j];
      if (matriz[i][j] == 1)
      {
        x = i;
        y = j;
      }
    }
  }
  for (int k = x - 1; k <= x + 1; k++)
  {
    if (k < x)
    {
      if (matriz[x - 2][y - 1] == 2)
      {
        peao++;
      }
      if (matriz[x - 2][y + 1] == 2)
      {
        peao++;
      }
      if (matriz[x - 1][y - 2] == 2)
      {
        peao++;
      }
      if (matriz[x - 1][y + 2] == 2)
      {
        peao++;
      }
    }
    if (k > x)
    {
      if (matriz[x + 1][y - 2] == 2)
      {
        peao++;
      }
      if (matriz[x + 1][y + 2] == 2)
      {
        peao++;
      }
      if (matriz[x + 2][y - 1] == 2)
      {
        peao++;
      }
      if (matriz[x + 2][y + 1] == 2)
      {
        peao++;
      }
    }
  }
  cout << peao;

  return 0;
}