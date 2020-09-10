#include <stdlib.h>
#include <iostream>
using namespace std;

int sequencia(int x, int y, int z)
{
  int aux = 0;

  if (z > 2)
  {
    aux = x;
    x = y;
    y = aux + y;
    cout << y << " ";
    sequencia(x, y, z - 1);
  }
  else
  {
    exit;
  }
}

int main()
{
  int x = 0, y = 1, z = 0;

  cin >> z;
  cout << x << " " << y << " ";

  sequencia(x, y, z);

  return 0;
}
