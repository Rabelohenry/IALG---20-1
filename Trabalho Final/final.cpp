//  Trabalho feito por HENRIQUE SILVA RABELO 10A
//  Especificações do trabalho:
//   - Sensores, Busca Binária, Shell Sort e modo de gravação binário
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//declaração do struct usado
struct sensores
{
  int id;
  string nome;
  string tipo;
  string aplicacao;
  string descricao;
};
//codigo de ordenação Shell Sort especificado na configuração do trabalho
void shell_sort(sensores sensor[], int *registros)
{
  int gaps[9] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
  int pos_gap = 8;

  while (gaps[pos_gap] > *registros)
  {
    pos_gap--;
  }

  sensores value;
  int j;
  while (pos_gap >= 0)
  {
    int gap = gaps[pos_gap];

    for (int i = gap; i < *registros; i++)
    {
      value = sensor[i];
      j = i;
      while ((j >= gap) and (value.id < sensor[j - gap].id))
      {
        sensor[j] = sensor[j - gap];
        j = j - gap;
      }
      sensor[j] = value;
    }
    pos_gap--;
  }
}
//Código de busca Binária também especificado na configuração do trabalho
int BuscaBinaria(sensores sensor[], int pos_inicial, int pos_final, int id)
{
  int meio = (pos_inicial + pos_final) / 2;

  if (id == sensor[meio].id)
  { //caso base: elemento encontrado
    return meio;
  }
  else if (pos_inicial < pos_final)
  { //caso geral: processo de busca
    if (sensor[meio].id < id)
      return BuscaBinaria(sensor, meio + 1, pos_final, id);
    else
      return BuscaBinaria(sensor, pos_inicial, meio - 1, id);
  }
  else
  { //caso base: elemento não encontrada
    return -1;
  }
}
//função para incluir um sensor no vetor de registros
void incluir(sensores sensor[], int *registros)
{
  int identificador, id;

  if (*registros < 100) //Verifica se tem menos de 100 sensores cadastrado
  {

    cout << "Incluir novo sensor no sistema" << endl
         << "ID: ";
    cin >> id;

    identificador = BuscaBinaria(sensor, 0, *registros - 1, id);

    if (identificador == -1) //caso nao exista aquele ID inicia o processo pra incluir um novo sensor
    {
      sensor[*registros].id = id;
      cin.ignore();
      cout << "Nome: ";
      getline(cin, sensor[*registros].nome);
      cout << "Tipo: ";
      getline(cin, sensor[*registros].tipo);
      cout << "Aplicacao: ";
      getline(cin, sensor[*registros].aplicacao);
      cout << "Decricao: ";
      getline(cin, sensor[*registros].descricao);

      cout << "Registro incluido com sucesso" << endl;

      *registros += 1; // controla quantos registros existem no vetor de struct
    }
    else //caso já exista um ID igual exibe esse mensagem para o usuário
    {
      cout << "Favor adicionar um sensor com id diferente de: " << id << endl;
    }
  }
  else // caso já tenha 100 registros de sensores
  {
    cout << "Nao e possivel inserir novo registro";
  }
}

//função para excluir um registro de sensor
void excluir(sensores sensor[], int *registros)
{
  int id, identificador;

  cout << "Qual o id do sensor que deseja exluir?" << endl
       << "ID: ";
  cin >> id;

  identificador = BuscaBinaria(sensor, 0, *registros - 1, id); //metodo que busca o id digitado pelo usuario

  if (identificador != -1) //caso o id exista pergunta se o usuario tem certeza que deseja excluir
  {
    string resposta;
    cout << "TEM CERTEZA QUE DESEJA EXCLUIR ESSE SENSOR?" << endl
         << endl;
    cout << "SENSOR ID: ";
    cout << sensor[identificador].id;
    cout << endl
         << "Nome: ";
    cout << sensor[identificador].nome;
    cout << endl
         << "Tipo: ";
    cout << sensor[identificador].nome;
    cout << endl
         << "Aplicacao: ";
    cout << sensor[identificador].aplicacao;
    cout << endl
         << "Decricao: ";
    cout << sensor[identificador].descricao << endl
         << "Sim ou nao (s / n): ";

    cin >> resposta;
    // se a resposta for SIM, desloca os registros da direita a partir da posição que deseja exluir uma posição para a esquerda
    //logo a posição desejada é substituida
    if (resposta == "s" || resposta == "S" || resposta == "sim" || resposta == "SIM" || resposta == "Sim")
    {
      for (int k = identificador; k < *registros - 1; k++)
      {
        sensor[k] = sensor[k + 1];
      }
      *registros -= 1; //diminui a variavel que representa a quantidade de registros de sensores
      cout << "Registro excluido com sucesso" << endl
           << endl;
    }
  }
  else // caso não encontre o ID digitado pelo usuario na busca binaria
  {
    cout << "Registro nao encontrado" << endl
         << endl;
  }
}

void listar(sensores sensor[], int *registro) //função que exibe os todos os registros de sensores
{
  cout << "Lista de Sensores Cadastrados: " << *registro << endl
       << endl;
  for (int i = 0; i < *registro; i++) // exibe os registros baseado na quantidade de sensores cadastrados
  {
    cout << "SENSOR ID: ";
    cout << sensor[i].id;
    cout << endl
         << "Nome: ";
    cout << sensor[i].nome;
    cout << endl
         << "Tipo: ";
    cout << sensor[i].tipo;
    cout << endl
         << "Aplicacao: ";
    cout << sensor[i].aplicacao;
    cout << endl
         << "Decricao: ";
    cout << sensor[i].descricao << endl
         << endl;
  }
}

void alterar(sensores sensor[], int *registros) //funcção que altera algum campo de um determinado registro
{
  int id, identificador;
  int campo;

  cout << "Informe o id do sensor e o campo que deseja alterar" << endl //solicita o ID pro usuario
       << "ID: ";
  cin >> id;
  cout << "Campo: 1 - nome / 2 - tipo / 3 - aplicacao / 4 - descricao/:" << endl; //e o campo que ele deseja alterar
  cin >> campo;

  identificador = BuscaBinaria(sensor, 0, *registros - 1, id); //busca o id informado pelo usario

  if (identificador != -1) //caso o id exista pergunta pro usuario se ele tem certeza da mudança
  {
    string resposta;

    switch (campo) //verifica qual campo o usuario deseja alterar e perguinta se ele tem certeza da mudança
    {
    case 1:
      cout << "TEM CERTEZA QUE DESEJA ALTERAR O CAMPO NOME DESSE SENSOR?" << endl;
      cout << "SENSOR ID: " << sensor[identificador].id << endl;
      cout << "NOME: " << sensor[identificador].nome << endl
           << "Sim ou nao (s / n): ";
      cin >> resposta;

      if (resposta == "s" || resposta == "S" || resposta == "sim" || resposta == "SIM" || resposta == "Sim")
      { //se a reposta for SIM solicita um novo valor para o campo
        cout << "Informe o novo valor do campo" << endl
             << "NOME: ";
        cin.ignore();
        getline(cin, sensor[identificador].nome);
        cout << "Registro alterado com sucesso" << endl;
      }
      break;
    case 2:
      cout << "TEM CERTEZA QUE DESEJA ALTERAR O CAMPO TIPO DESSE SENSOR?" << endl;
      cout << "SENSOR ID: " << sensor[identificador].id << endl;
      cout << "TIPO: " << sensor[identificador].tipo << endl
           << "Sim ou nao (s / n): ";
      cin >> resposta;

      if (resposta == "s" || resposta == "S" || resposta == "sim" || resposta == "SIM" || resposta == "Sim")
      { //se a reposta for SIM solicita um novo valor para o campo
        cout << "Informe o novo valor do campo" << endl
             << "TIPO: ";
        cin.ignore();
        getline(cin, sensor[identificador].tipo);
        cout << "Registro alterado com sucesso" << endl;
      }
      break;
    case 3:
      cout << "TEM CERTEZA QUE DESEJA ALTERAR O CAMPO APLICACAO DESSE SENSOR?" << endl;
      cout << "SENSOR ID: " << sensor[identificador].id << endl;
      cout << "APLICACAO: " << sensor[identificador].aplicacao << endl
           << "Sim ou nao (s / n): ";
      cin >> resposta;

      if (resposta == "s" || resposta == "S" || resposta == "sim" || resposta == "SIM" || resposta == "Sim")
      { //se a reposta for SIM solicita um novo valor para o campo
        cout << "Informe o novo valor do campo" << endl
             << "APLICACAO: ";
        cin.ignore();
        getline(cin, sensor[identificador].aplicacao);
        cout << "Registro alterado com sucesso" << endl;
      }
      break;
    case 4:
      cout << "TEM CERTEZA QUE DESEJA ALTERAR O CAMPO DESCRICAO DESSE SENSOR?" << endl;
      cout << "SENSOR ID: " << sensor[identificador].id << endl;
      cout << "DESCRICAO: " << sensor[identificador].descricao << endl
           << "Sim ou nao (s / n): ";
      cin >> resposta;

      if (resposta == "s" || resposta == "S" || resposta == "sim" || resposta == "SIM" || resposta == "Sim")
      { //se a reposta for SIM solicita um novo valor para o campo
        cout << "Informe o novo valor do campo" << endl
             << "DESCRICAO: ";
        cin.ignore();
        getline(cin, sensor[identificador].descricao);
        cout << "Registro alterado com sucesso" << endl;
      }
      break;
    default:
      cout << "Na proxima tentativa informe um numero valido que representa o campo" << endl;
      break;
    }
  }
  else //caso o Id não exista nos registros
  {
    cout << "Registro nao encontrado" << endl
         << endl;
  }
}

string gravar(sensores sensor[], int *registros) //funçao que grava os registros em um arquivo binário
{
  ofstream arquivo("arquivo.bin"); //abre o arquivo

  if (arquivo) //verifica se o arquivo esta disponivel para uso
  {
    arquivo.write((const char *)(&sensor),
                  sizeof(sensores));
    return "Gravacao realizada com sucesso";
  }
  else // caso o arquivo não pode ser acessado
  {
    return "O arquivo nao pode ser utilizado";
  }
}

int main() //função principal do programa
{
  sensores *sensor = new sensores[100]; //aloca dinamicamente um vetor de structs com 100 posições

  int acao = -1;
  int registros = 0;
  string resposta;

  cout << endl
       << "**BEM VINDO AO SISTEMA DE SENSORES**" << endl
       << endl;

  while (acao != 6) //recebe as repostas do usuario para qual funcionalidade ele deseja usar
  {
    cout << "Qual tipo de funcionalidade do sistema deseja utilizar?" << endl
         << "1 - INCLUIR um novo sensor no sistema- digite o numero 1" << endl
         << "2 - EXCLUIR um sensor do sistema - digite o numero 2" << endl
         << "3 - LISTAR os sensores cadastrados - digite o numero 3" << endl
         << "4 - ALTERAR um sensor ja cadastrados - digite o numero 4" << endl
         << "5 - GRAVAR os sensores cadastrados no arquivo - digite o numero 5" << endl
         << "6 - SAIR do sistema - digite o numero 6" << endl
         << ": ";

    cin >> acao;

    switch (acao) // baseado na escolha do usuario chama a função necessária
    {
    case 1:
      incluir(sensor, &registros);
      shell_sort(sensor, &registros); //ordena o vetor de structs baseado no id
      break;
    case 2:
      excluir(sensor, &registros);
      break;
    case 3:
      listar(sensor, &registros);
      break;
    case 4:
      alterar(sensor, &registros);
      break;
    case 5:
      cout << gravar(sensor, &registros) << endl;
      break;
    case 6: //caso o usuario escolha a opçao siar pergunta se ele deseja salvar o arquivo
      cout << "Deseja salvar os dados no arquivo?" << endl
           << "Sim ou nao (s / n): ";
      cin >> resposta;
      if (resposta == "s" || resposta == "S" || resposta == "sim" || resposta == "SIM" || resposta == "Sim")
        cout << gravar(sensor, &registros) << endl;
      break;
    default:
      cout << "Digite uma opcao valida de numero por favor!!" << endl;
    }
  }

  delete[] sensor; // libera a memória ocupada pelo vetor de structs

  return 0;
}