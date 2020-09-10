#include <iostream>
#include <fstream>

using namespace std;

struct dados{

  char nome[50];
  int id;
  char tel[12];
};

int insertion_sort(dados vetor[], int tam){
    dados valor_pivo;
    int j;
    for (int a = 1; a < tam; a++) {
   	 valor_pivo = vetor[a];
   	 j = a - 1;
   	 while ((j >= 0) and (valor_pivo.id < vetor[j].id)){
   		 vetor[j+1] = vetor[j];
   		 j--;
   	 }
   	 vetor[j+1] = valor_pivo;
    }
}

int main(){

  fstream arquivo("caravana.bin", ios::in|ios::out|ios::binary);

  dados cliente;
  int num;
  cin>>num;

  for (int i = 0; i < num; i++)
  {
    cin>>cliente.nome>>cliente.id>>cliente.tel;
    arquivo.write((const char *) (&cliente),
    sizeof(dados));
  }

  int metade, busca,altera;
  int aux = 0;

  cin>>busca>>altera;

  while(aux <= num)
  {
    metade = (aux + num)/2;
    dados novo;

    arquivo.seekg(metade*sizeof(dados), ios::beg);
    arquivo.read((char *) (&novo),
    sizeof(dados));

    if(novo.id == busca){
      
      novo.id = altera;
      arquivo.seekg(metade*sizeof(dados), ios::beg);
      arquivo.write((const char *) (&novo), sizeof(dados));
      aux = num + 1;

    }else if(novo.id < busca){

      aux = metade + 1;

    }else if(novo.id > busca){

      num = metade - 1;

    }
  }
  dados final[num];
  arquivo.seekg (0, arquivo.beg);
  for (int k = 0; k < num; k++)
  {
    arquivo.read((char *) (&final[k]),
    sizeof(dados));
  }
  
  insertion_sort(final,num);

  arquivo.seekp (0, arquivo.beg);

  for (int l = 0; l < num; l++)
  {
    arquivo.write((char *) (&final[l]),
    sizeof(dados));

    cout<<final[l].nome<<" "<<final[l].id<<endl;
  }

  return 0;
}