#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  string palavra, busca;
  int tamanho_palavra, tamanho_busca, pos = 0, igual = 0, cont = 0;

  cin >> palavra >> busca;

  tamanho_palavra = palavra.length();
  tamanho_busca = busca.length();

  for (int i = 0; i < tamanho_palavra; i++)
  {
    if (palavra[i] == busca[0])
    {
      for (int j = 0; j < tamanho_busca; j++)
      {
        if (palavra[i + j] == busca[j])
        {
          igual++;
        }
        else
        {
          igual = 0;
        }
      }
    }
    if (tamanho_busca == igual && cont == 0)
    {
      pos = i;
      cout << pos;
      cont++;
    }
  }

  if (cont == 0)
  {
    cout << "-1";
  }

  return 0;
}