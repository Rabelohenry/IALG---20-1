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
      return j;
    }
    swap(vetor[i], vetor[j]);
  }
}

void selection_sort(vector<int> &vetor, int inicio, int fim)
{
  int menor, aux_troca;
  for (int indice = inicio; indice < fim - 1; indice++)
  {
    menor = indice;
    for (int j = indice + 1; j < fim; j++)
    {
      if (vetor[j] < vetor[menor])
      {
        menor = j;
      }
    }
    aux_troca = vetor[indice];
    vetor[indice] = vetor[menor];
    vetor[menor] = aux_troca;
  }
}

void quicksort(vector<int> &vetor, int pos_pivo, int fim, int max)
{
  int pos_novo_pivo;
  if (pos_pivo < fim)
  {
    pos_novo_pivo = particiona(vetor, pos_pivo, fim);

    if ((pos_novo_pivo - pos_pivo) - 1 >= max)
    {
      quicksort(vetor, pos_pivo, pos_novo_pivo, max);
    }
    else
    {
      selection_sort(vetor, pos_pivo, pos_novo_pivo + 1);
    }

    if (fim - pos_novo_pivo + 1 >= max)
    {
      quicksort(vetor, pos_novo_pivo + 1, fim, max);
    }
    else
    {
      selection_sort(vetor, pos_novo_pivo + 1, fim + 1);
    }
  }
}

int main()
{
  int qtde, max;

  cin >> max >> qtde;

  vector<int> vetor(qtde);

  for (int k = 0; k < qtde; k++)
  {
    cin >> vetor.at(k);
  }

  quicksort(vetor, 0, qtde - 1, max);

  for (int n = 0; n < qtde; n++)
  {
    cout << vetor[n] << " ";
  }

  return 0;
}