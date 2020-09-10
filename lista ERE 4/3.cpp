#include <iostream>
#include <vector>
using namespace std;

int particiona(vector<int> &vetor, int inicio, int fim)
{
  int pivo = vetor[inicio + (fim - inicio) / 2];
  int i = inicio - 1;
  int j = fim + 1;
  while (true)
  {
    do
    {
      i++;
    } while (vetor[i] < pivo);
    do
    {
      j--;
    } while (vetor[j] > pivo);
    if (i >= j)
    {
      cout << pivo << ":";
      for (int y = inicio; y < fim + 1; y++)
      {
        cout << " " << vetor[y];
      }
      cout << endl;
      return j;
    }
    swap(vetor[i], vetor[j]);
  }
}

void quicksort(vector<int> &vetor, int pos_pivo, int fim)
{
  int pos_novo_pivo;
  if (pos_pivo < fim)
  {
    pos_novo_pivo = particiona(vetor, pos_pivo, fim);
    quicksort(vetor, pos_pivo, pos_novo_pivo);
    quicksort(vetor, pos_novo_pivo + 1, fim);
  }
}

int main()
{
  int qtde;

  cin >> qtde;

  vector<int> vetor(qtde);

  for (int k = 0; k < qtde; k++)
  {
    cin >> vetor.at(k);
  }

  quicksort(vetor, 0, qtde - 1);

  for (int n = 0; n < qtde; n++)
  {
    cout << vetor[n] << " ";
  }

  return 0;
}