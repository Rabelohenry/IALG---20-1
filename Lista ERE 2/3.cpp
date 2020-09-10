#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int ingre1, ingre2, igual = 0, nada = 0;

  cin >> ingre1;

  string nomes1[ingre1];

  for (int i = 0; i < ingre1; i++)
  {
    cin >> nomes1[i];
  }

  cin >> ingre2;

  string nomes2[ingre2];

  for (int j = 0; j < ingre2; j++)
  {
    cin >> nomes2[j];
  }

  for (int l = 0; l < ingre1; l++)
  {
    for (int k = 0; k < ingre2; k++)
    {
      if (nomes1[l] == nomes2[k])
      {
        igual++;
      }
    }

    if (igual == 0)
    {
      cout << nomes1[l] << endl;
      nada++;
    }
    igual = 0;
  }

  if (nada == 0)
  {
    cout << "NADA";
  }
  return 0;
}