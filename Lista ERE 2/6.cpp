#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int num, altera, aux, alt = 0;

  cin >> num;

  int vetor[num];

  for (int i = 0; i < num; i++)
  {
    cin >> vetor[i];
  }

  cin >> altera;

  for (int j = 0; j < num; j++)
  {
    if (vetor[j] == altera)
    {
      for (int k = j; k < num; k++)
      {
        aux = vetor[k + 1];
        vetor[k] = aux;
      }
      alt++;
    }
  }

  if (alt != 0)
  {
    for (int l = 0; l < num - 1; l++)
    {
      cout << vetor[l] << " ";
    }
  }
  else
  {
    cout << "ELEMENTO NAO ENCONTRADO";
  }

  return 0;
}