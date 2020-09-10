#include <iostream>
using namespace std;

struct pokemon
{
  string nome;
  int atq, def;
};

struct treinador
{
  string nome, pokemom;
};

void duelo(int A, int B, struct treinador treinador[], struct pokemon pokemon[])
{
  int atq, def;
  if (pokemon[A * 3].atq >= pokemon[A * 3 + 1].atq and pokemon[A * 3].atq >= pokemon[A * 3 + 2].atq)
  {
    atq = A * 3;
  }
  else if (pokemon[A * 3].atq <= pokemon[A * 3 + 1].atq and pokemon[A * 3 + 2].atq <= pokemon[A * 3 + 1].atq)
  {
    atq = A * 3 + 1;
  }
  else
  {
    atq = A * 3 + 2;
  }

  if (pokemon[B * 3].def >= pokemon[B * 3 + 1].def and pokemon[B * 3].def >= pokemon[B * 3 + 2].def)
  {
    def = B * 3;
  }
  else if (pokemon[B * 3].def <= pokemon[B * 3 + 1].def and pokemon[B * 3 + 2].def <= pokemon[B * 3 + 1].def)
  {
    def = B * 3 + 1;
  }
  else
  {
    def = B * 3 + 2;
  }

  if (pokemon[atq].atq > pokemon[def].def)
  {
    cout << treinador[A].nome << endl
         << pokemon[atq].nome;
  }
  else
  {
    cout << treinador[B].nome << endl
         << pokemon[def].nome;
  }
}

int main()
{

  int n, j = 0, desafiante, lider;

  cin >> n;

  treinador treinador[n];
  pokemon pokemon[n * 3];

  for (int i = 0; i < n; i++)
  {
    cin >> treinador[i].nome >> pokemon[j].nome >> pokemon[j].atq >> pokemon[j].def >> pokemon[j + 1].nome >> pokemon[j + 1].atq >> pokemon[j + 1].def >> pokemon[j + 2].nome >> pokemon[j + 2].atq >> pokemon[j + 2].def;
    j += 3;
  }
  cin >> desafiante >> lider;

  duelo(desafiante, lider, treinador, pokemon);

  return 0;
}