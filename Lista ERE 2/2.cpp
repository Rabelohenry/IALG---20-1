#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int vetor[10], n, aux1, aux2, pos, element;

  cin >> n;

  for (int i = 0; i < 10; i++)
  {
    vetor[i] = 0;
  }

  for (int k = 0; k < n; k++)
  {
    cin >> vetor[k];
  }

  cin >> element >> pos;

  for (int j = 0; j < 10; j++)
  {
    if (j == pos)
    {
      aux1 = vetor[j];
      vetor[j] = element;
    }
    else if (j > pos)
    {
      aux2 = vetor[j];
      vetor[j] = aux1;
      aux1 = aux2;
    }
  }

  for (int m = 0; m < 10; m++)
  {
    cout << vetor[m] << " ";
  }

  return 0;
}