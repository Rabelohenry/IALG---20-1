#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  ifstream arquivo("tropas.txt");

  string dados,sinal;
  string matriz[10][10];
  string westeros, inimigos;

  int tropasW,tropasI,x,y;
  int cont = 0,aux = 0,aux2 = 0;

  if (arquivo)
  {
    while (getline(arquivo, dados))
    { 
      if(cont == 0){
          westeros = dados;
      }
      else if(cont == 1){
          inimigos = dados;
      }
      
      if(cont == 3){
        tropasW = stoi(dados);
      }
      else if (aux < tropasW and cont > 3){
        x= dados[0] - '0';
        y= dados[2] - '0';
        matriz[x][y] = westeros;
        aux++;  
      }
      
      if(cont == tropasW + 5){
         tropasI = stoi(dados);
      }
      else if (aux2<tropasI and cont>4+tropasW and cont<=5+tropasW+tropasI)
      {
        x= dados[0] - '0';
        y= dados[2] - '0';
        matriz[x][y] = inimigos;
        aux2++;  
      }
      else if (cont == 7+tropasW+tropasI and cont!=0 )
      {
        sinal = dados;
      }
      cont++;
    }
    arquivo.close();
  }

  for (int k = 0; k < 10; k++)
  {
    for (int l = 0; l < 10; l++)
    {
      if (matriz[k][l]!=westeros and matriz[k][l]!= inimigos)
        if (l == 0)
          cout<<sinal;
        else
          cout<<" "<<sinal;
        
      else    
        cout<<" "<< matriz[k][l];
    }
    if (k!=9)
      cout<<endl;
  }
  
  cout<<endl<<westeros<<":";

  for (int i = 0; i < 10; i++)
  {
    int w = 0,y = 0;
    for (int j = 0; j < 10; j++)
    {
      if(matriz[i][j]==inimigos)
        y++;
      else if(matriz[i][j]==westeros) 
        w++; 
    }
    if(w>y)
      cout<<" "<<i;    
  }
  

  return 0;
}