#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

  int n;
  string palavra;

  cin >> palavra;

  n = palavra.length();

  for (int i = 0; i < n; i++)
  {
    int repete = 0;
    for (int j = 0; j < n; j++)
    {
      if (i != j && palavra[i] == palavra[j])
      {
        repete++;
      }
    }

    if (repete == 0)
    {
      cout << palavra[i];
      i = n;
    }
  }

  return 0;
}