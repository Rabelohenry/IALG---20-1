#include <iostream>
#include <cstdlib>
using namespace std;

int divisao(int vetor[], int num, int tamanho, int left, int altera, int length, int x)
{
  if (tamanho >= left)
  {
    int meio = left + (tamanho - left) / 2;
    length++;
    if (vetor[meio] == num)
    {
      x = 1;
      vetor[meio] = altera;
      for (int i = 0; i <= sizeof(vetor) + 1; i++)
      {
        cout << vetor[i] << " ";
      }
      cout << endl
           << length;
    }
    if (vetor[meio] > num)
    {
      return divisao(vetor, num, meio - 1, left, altera, length, x);
    }
    return divisao(vetor, num, tamanho, meio + 1, altera, length, x);
  }
  if (x != 1)
  {
    for (int j = 0; j <= sizeof(vetor); j++)
    {
      cout << vetor[j] << " ";
    }
    cout << endl
         << length;
  }
  return -1;
}

int main()
{
  int tamanho, altera, num, passou = 0, x = 0;

  cin >> tamanho;

  int vetor[tamanho];

  for (int i = 0; i < tamanho; i++)
  {
    cin >> vetor[i];
  }
  vetor[tamanho + 1] = 0;
  cin >> num >> altera;

  divisao(vetor, num, tamanho - 1, 0, altera, passou, x);

  return 0;
}