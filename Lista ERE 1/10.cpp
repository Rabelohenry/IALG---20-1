#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
  int x, i = 1;
  float soma = 0;

  cin >> x;

  while (i <= x)
  {
    soma = soma + i * 1.0 * (i * 1.0 + 1) / (i * 1.0 + 3);
    i++;
  }

  cout << soma;

  return 0;
}
