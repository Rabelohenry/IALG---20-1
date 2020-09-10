#include <stdlib.h>
#include <iostream>
using namespace std;

float verifica(float m, float cm, float mm, float mR, float cmR, float mmR)
{
  float alturaIdeal, alturaReal;

  alturaIdeal = (m * 100) + (cm) + (mm / 10);
  alturaReal = (mR * 100) + (cmR) + (mmR / 10);

  if (alturaReal > alturaIdeal)
  {
    cout << "nao";
  }
  else
  {
    cout << "sim";
  }
}

int main()
{
  float m = 0, cm = 0, mm = 0, mR = 0, cmR = 0, mmR = 0;

  cin >> m >> cm >> mm >> mR >> cmR >> mmR;

  verifica(m, cm, mm, mR, cmR, mmR);

  return 0;
}
