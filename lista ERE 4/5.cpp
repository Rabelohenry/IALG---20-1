#include <iostream>
#include <vector>
using namespace std;

void intercala(vector<int> &vetor, int inicio, int meio, int fim)
{
  int i = inicio, j = meio + 1;
  int tamanho = fim - inicio + 1;
  int aux[tamanho]; // vetor auxiliar

  for (int z = inicio; z <= meio; z++)
  {
    cout << vetor[z] << " ";
  }
  cout << "+ ";
  for (int a = j; a <= fim; a++)
  {
    cout << vetor[a] << " ";
  }

  for (int k = 0; k < tamanho; k++)
  {
    if ((i <= meio) and (j <= fim))
    {
      if (vetor[i] <= vetor[j])
      {
        aux[k] = vetor[i]; // copia trecho1 em aux[]
        i++;               // avança em trecho1
      }
      else
      {
        aux[k] = vetor[j]; // copia trecho2 em aux[]
        j++;               // avanca em trecho2
      }
    }
    else if (i > meio)
    { // terminou o trecho1
      aux[k] = vetor[j];
      j++;
    }
    else
    { // terminou o trecho2
      aux[k] = vetor[i];
      i++;
    }
  }
  cout << "= ";
  for (int l = 0; l < tamanho; l++)
  {
    vetor[inicio + l] = aux[l];
    cout << aux[l] << " ";
  }
  cout << endl;
}

void mergesort(vector<int> &vetor, int inicio, int fim)
{
  int meio;
  if (inicio < fim)
  {
    meio = (inicio + fim) / 2;
    mergesort(vetor, inicio, meio);
    mergesort(vetor, meio + 1, fim);
    intercala(vetor, inicio, meio, fim);
  }
}

int main()
{
  int qtde;

  cin >> qtde;

  vector<int> vetor(qtde);

  for (int x = 0; x < qtde; x++)
  {
    cin >> vetor.at(x);
  }

  mergesort(vetor, 0, qtde - 1);

  return 0;
}