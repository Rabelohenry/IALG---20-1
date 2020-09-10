#include <stdlib.h>
#include <iostream>
using namespace std;

int multiplica(int x, int y)
{
  if (y == 1)
  {
    return x;
  }
  else
  {
    return x + multiplica(x, y - 1);
  }
}

int main()
{
  int x, y, var;

  cin >> x >> y;

  var = multiplica(x, y);

  cout << var;

  return 0;
}
