#include <iostream>
using namespace std;

struct funcionario
{
  int codigo;
  float horas, valHora, total;
};

int ordena(float total[], struct funcionario funcionario[], int funcionarios)
{
  float aux_troca;
  for (int l = 0; l < funcionarios - 1; l++)
  {
    for (int j = 0; j < funcionarios - 1 - l; j++)
    {
      if (total[j] > total[j + 1])
      {
        aux_troca = total[j];
        total[j] = total[j + 1];
        total[j + 1] = aux_troca;
      }
    }
  }

  for (int k = 0; k < funcionarios; k++)
  {
    for (int t = 0; t < funcionarios; t++)
    {
      if (total[k] == funcionario[t].total)
      {
        cout << funcionario[t].codigo << " " << funcionario[t].total << endl;
      }
    }
  }
}

int main()
{
  int funcionarios;

  cin >> funcionarios;

  funcionario funcionario[funcionarios];
  float total[funcionarios];

  for (int i = 0; i < funcionarios; i++)
  {
    cin >> funcionario[i].codigo >> funcionario[i].horas >> funcionario[i].valHora;
    funcionario[i].total = funcionario[i].horas * funcionario[i].valHora;
    total[i] = funcionario[i].total;
  }

  ordena(total, funcionario, funcionarios);

  return 0;
}