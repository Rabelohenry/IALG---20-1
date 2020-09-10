#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

float juros(float c, float i, int t)
{
  float m;
  float x;
  x = pow(1 + i / 100, t);
  m = c * x;

  return m;
}

int main()
{
  int t = 0;
  float c = 0, i = 0;

  cin >> c >> i >> t;

  cout << juros(c, i, t);

  return 0;
}
