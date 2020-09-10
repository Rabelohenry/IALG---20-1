#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  string nomes[10];
  int vendas[10], vendaTotal = 0, pos = 0;
  float percent[10], total[10];

  for (int i = 0; i < 10; i++)
  {
    cin >> nomes[i] >> vendas[i] >> percent[i];
    total[i] = vendas[i] * percent[i];
    vendaTotal = vendaTotal + vendas[i];
  }

  for (int k = 0; k < 10; k++)
  {
    cout << nomes[k] << " " << total[k] << endl;
  }

  cout << endl
       << vendaTotal << endl;

  for (int j = 0; j < 10; j++)
  {
    if (total[j] > total[pos])
    {
      pos = j;
    }
  }
  cout << nomes[pos] << " " << total[pos];

  return 0;
}