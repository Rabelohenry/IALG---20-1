#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
  int x, y = 1, i = 1, z = 0;

  cin >> x;

  while (i <= x)
  {

    while (y <= i)
    {
      if (i % y == 0)
      {
        z++;
      }
      else if (i == 1 && y == 1)
      {
        cout << i << " ";
      }
      y++;
    }
    if (z % 2 != 0)
    {
      cout << i << " ";
    }

    y = 1;
    z = 0;
    i++;
  }

  return 0;
}
