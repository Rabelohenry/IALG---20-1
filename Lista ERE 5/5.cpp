#include <iostream>
#include <fstream>

using namespace std;

int compara(int **navios, int **bombas, int m){

  int afundado = 0;
  
  for (int a = 0; a < m; a++)
  {
    int navio,tamanho = 0,bomba = 0;
    int direcao;

    for (int b = 0; b < m; b++)
    {
      if(navios[a][b] != 0 && navios[a][b]){ //tem navio
        navio = navios[a][b];// numero do navio
       
        if (bombas[a][b]== 1) // verifica se tem bomba
        {
          if (navios[a][b+1] == navio )
          {
            direcao = 0; // navio pra direita
          }else if(navios[a+1][b] == navio){
            direcao = 1; // navio pra baixo
          }

          if (direcao == 0) // se for pra direita
          {
            for (int c = b; c < m; c++)
            {
              if (navios[a][c] == navio){
                tamanho++;
              }
              if(bombas[a][c] == 1 && navios[a][c] == navio){
                bomba++;
              }
              navios[a][c] = 0;
            } 
          }else if (direcao == 1){//se for pra baixo
            for (int c = a; c < m; c++)
            {
              if (navios[c][b] == navio){
                tamanho++;
              }
              if(bombas[c][b] == 1 && navios[c][b] == navio){ 
                bomba++;
              }
              navios[c][b] = 0;
            } 
          }
          if (bomba >= tamanho)
            afundado++;
        }
      tamanho = 0;
      bomba = 0; 
      }
    }  
  }
  return afundado;
}

int main(){

  ifstream arquivo("BatalhaNaval.txt");

  int m;
  int **navios;
  int **bombas;

  if (arquivo)
    {
      arquivo>>m;

      navios =  new int*[m];
      bombas =  new int*[m];

      for (int i = 0; i < m; i++){
        navios[i] = new int[m];
        bombas[i] = new int[m];
      }
        
      for (int j = 0; j < m; j++)
      {
        for (int h = 0; h < m; h++)
        {
          arquivo>>navios[j][h];
        }
      }
      
      for (int k = 0; k < m; k++)
      {
        for (int l = 0; l < m; l++)
        {
          arquivo>>bombas[k][l];
        }
      }

      arquivo.close();
    }

    cout<<compara(navios,bombas,m);

    for (int y = 0; y < m; y++){
    // aqui se desalocam as colunas de cada linha
    delete[] navios[y]; 
    delete[] bombas[y]; 
    }
    delete[] navios;
    delete[] bombas;

  return 0;
}