#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int l, permite = 0;

  cin >> l;

  int matriz[l][l];

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < l; j++)
    {
      cin >> matriz[i][j];
    }
  }

  for (int k = 0; k < l; k++)
  {
    for (int o = 0; o < l; o++)
    {
      if (matriz[k][o] == 0 and matriz[k][o + 4] == 0 and o + 4 < l)
      {
        permite++;
      }
    }
  }

  cout << permite;

  return 0;
}