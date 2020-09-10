#include <iostream>
#include <vector>
using namespace std;

void shell_sort(vector<float> vetor)
{
  int size = vetor.size();
  int gaps[5] = {1, 3, 7, 15, 31};
  int pos_gap = 4, aux = 0;
  while (gaps[pos_gap] > size)
  {
    pos_gap--;
  }
  float value;
  int j;
  while (pos_gap >= 0)
  {
    int gap = gaps[pos_gap];
    cout << gap << ": ";

    for (int i = gap; i < size; i++)
    {
      value = vetor[i];
      j = i;
      while ((j >= gap) and (value < vetor[j - gap]))
      {
        vetor[j] = vetor[j - gap];
        j = j - gap;
        aux++;
      }
      vetor[j] = value;
      aux++;
    }
    for (int l = 0; l < size; l++)
    {
      cout << vetor[l] << " ";
    }
    cout << endl;

    pos_gap--;
  }
  cout << aux;
}

int main()
{
  int qtde;

  cin >> qtde;

  vector<float> vetor(qtde);

  for (int k = 0; k < qtde; k++)
  {
    cin >> vetor.at(k);
  }

  shell_sort(vetor);

  return 0;
}