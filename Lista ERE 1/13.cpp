#include <iostream>
using namespace std;

int aumenta(int x)
{
  x++;
  return x;
}

int diminui(int x)
{
  x--;
  return x;
}

int soma(int x, int y, int i)
{
  if (i > 0)
  {
    if (y < 0)
      return soma(diminui(x), y, i - 1);
    else
      return soma(aumenta(x), y, i - 1);
  }

  return x;
}

int main()
{
  int x, y, i;

  cin >> x >> y;
  if (y < 0)
    i = y * (-1);
  else
    i = y;

  cout << soma(x, y, i) << endl;

  return 0;
}
