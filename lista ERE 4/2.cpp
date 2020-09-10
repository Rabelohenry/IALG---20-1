#include <iostream>
#include <vector>
using namespace std;

void shell_sort(vector<int> vetor, vector<int> gaps)
{
  int size = vetor.size();
  int pos_gap = gaps.size() - 1;
  int aux = 0;
  aux++;
  while (gaps[pos_gap] > size)
  {
    pos_gap--;
    aux++;
  }
  int value;
  int j;
  aux++;
  while (pos_gap >= 0)
  {
    int gap = gaps[pos_gap];
    aux++;
    for (int i = gap; i < size; i++)
    {
      value = vetor[i];
      j = i;
      aux++;
      while ((j >= gap) and (value > vetor[j - gap]))
      {
        vetor[j] = vetor[j - gap];
        j = j - gap;
        aux++;
      }
      vetor[j] = value;
      aux++;
    }
    pos_gap--;
    aux++;
  }
  cout << aux;
}

int main()
{
  int qtde, gap;

  cin >> qtde;

  vector<int> vetor(qtde);

  for (int k = 0; k < qtde; k++)
  {
    cin >> vetor.at(k);
  }

  cin >> gap;

  vector<int> gaps(gap);

  for (int m = 0; m < gap; m++)
  {
    cin >> gaps.at(m);
  }

  shell_sort(vetor, gaps);

  return 0;
}