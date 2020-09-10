#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string contrario = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    string nome;

    cin >> nome;

    ifstream arquivo(nome);
    ofstream escreve("cifrado.txt");
    string dados;
    int espaco = 0;
    int x =0;
    if (arquivo and escreve)
    {
        while (getline(arquivo, dados))
        {
          int size = dados.size();

          if(x!=0) 
            escreve<<endl; 
          for (int j = 0; j < size; j++)
          {
              for (int i = 0; i < 26; i++)
              {
                  if (dados[j] == alfabeto[i]){  
                      escreve << contrario[i];
                      espaco=0;
                  }
                  else if (dados[j] == ' ' and espaco!=1 and j < size-1){
                    escreve << " ";
                    espaco = 1;
                  }
              }
          }
          x++;
        }
        arquivo.close();
    }

    return 0;
}