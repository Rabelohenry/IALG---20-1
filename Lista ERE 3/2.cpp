#include <iostream>
using namespace std;

struct soldado
{
  string planeta, nome;
  int numBatalha;

};

struct planeta
{
  string nome;
  int numSoldados, batalhas;
};

int main()
{
  int n, j = 0, igual = 0;

  cin >> n;

  soldado storm[n];
  planeta dados[n];

  for (int m = 0; m < n; m++)
  {
    storm[m].nome = "";
    storm[m].planeta = "";
    storm[m].numBatalha = 0;
    dados[m].nome = "";
    dados[m].numSoldados = 0;
    dados[m].batalhas = 0;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> storm[i].nome >> storm[i].planeta >> storm[i].numBatalha;

    if (i == 0 || dados[0].nome == storm[i].planeta)
    {
      dados[0].nome = storm[i].planeta;
      dados[0].numSoldados++;
      dados[0].batalhas += storm[i].numBatalha;
      if (j == 0)
      {
        j++;
      }
    }
    else
    {
      for (int k = 1; k <= j; k++)
      {
        if (dados[k].nome == storm[i].planeta)
        {
          dados[k].numSoldados++;
          dados[k].batalhas += storm[i].numBatalha;
          igual++;
        }
      }
      if (igual == 0)
      {
        {
          dados[j].nome = storm[i].planeta;
          dados[j].numSoldados++;
          dados[j].batalhas += storm[i].numBatalha;
          j++;
        }
      }
    }
  }

  for (int l = 0; l < j; l++)
  {
    cout << dados[l].nome << " " << dados[l].numSoldados << " " << dados[l].batalhas * 1.0 / dados[l].numSoldados << endl;
  }

  return 0;
}