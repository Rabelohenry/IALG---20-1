#include <iostream>
#include <cstdlib>
using namespace std;

struct doador
{
  string nome, tipo;
};

int main()
{
  int n;
  string comparar, aux1, aux2;

  cin >> n;

  doador doadores[n];

  for (int i = 0; i < n; i++)
  {
    cin >> doadores[i].nome;
    cin >> doadores[i].tipo;
  }
  cin >> comparar;

  if (comparar == "A")
  {
    aux1 = "A";
  }
  else if (comparar == "B")
  {
    aux1 = "B";
  }

  if (comparar != "AB" and comparar != "O")
  {
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < n; k++)
      {
        if (j == 0)
        {
          if (doadores[k].tipo == aux1)
          {
            cout << doadores[k].nome
                 << endl;
          }
        }
        else
        {
          if (doadores[k].tipo == "O")
          {
            cout << doadores[k].nome
                 << endl;
          }
        }
      }
    }
  }
  else if (comparar == "AB")
  {
    for (int l = 0; l < 4; l++)
    {
      for (int m = 0; m < n; m++)
      {
        if (l == 0 and doadores[m].tipo == "AB")
        {
          cout << doadores[m].nome
               << endl;
        }
        else if (l == 1 and doadores[m].tipo == "A")
        {
          cout << doadores[m].nome
               << endl;
        }
        else if (l == 2 and doadores[m].tipo == "B")
        {
          cout << doadores[m].nome
               << endl;
        }
        else if (l == 3 and doadores[m].tipo == "O")
        {
          cout << doadores[m].nome
               << endl;
        }
      }
    }
  }
  else
  {
    for (int y = 0; y < n; y++)
    {
      if (doadores[y].tipo == "O")
      {
        cout << doadores[y].nome
             << endl;
      }
    }
  }

  return 0;
}