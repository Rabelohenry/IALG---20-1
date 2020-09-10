#include <iostream>
using namespace std;

struct figurinha
{
  int codigo, quant;
  string nome;
};

int procura(int codigo[], struct figurinha figurinha[], int quant, int busca)
{

  int k = 0;
  int resultado;
  while (k < quant && busca > codigo[k])
  {
    k++;

    if (k < quant && busca == codigo[k])
    {
      resultado = k;
    }
    else
    {
      resultado = -1;
    }
  }
  cout << resultado << endl;
  for (int l = 0; l < quant; l++)
  {
    if (figurinha[l].codigo == codigo[resultado])
    {
      cout << figurinha[l].nome << " " << figurinha[l].quant;
    }
  }
}

int ordena(int codigo[], struct figurinha figurinha[], int quant, int busca)
{
  int menor, aux_troca;
  for (int indice = 0; indice < quant - 1; indice++)
  {
    menor = indice;
    for (int j = indice + 1; j < quant; j++)
    {
      if (codigo[j] < codigo[menor])
      {
        menor = j;
      }
    }
    aux_troca = codigo[indice];
    codigo[indice] = codigo[menor];
    codigo[menor] = aux_troca;
  }
  procura(codigo, figurinha, quant, busca);
}

int main()
{
  int quant, busca;

  cin >> quant;

  int codigo[quant];
  figurinha figurinha[quant];

  for (int i = 0; i < quant; i++)
  {
    cin >> figurinha[i].codigo >> figurinha[i].nome >> figurinha[i].quant;
    codigo[i] = figurinha[i].codigo;
  }

  cin >> busca;

  ordena(codigo, figurinha, quant, busca);

  return 0;
}