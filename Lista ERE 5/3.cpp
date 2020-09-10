#include<iostream>
#include<cstring>
using namespace std;

int main(){

  char a[100],b[100];

  cin.getline(a, 100);   
 
  cin.getline(b, 100);    

  int tamA = strlen(a);
  int tamB = strlen(b);

  int tamanho = tamA+ tamB + 1;
  
  char *resulta = new char[tamanho];

  for (int i = 0; i <= tamA; i++)
  { 
    if(i!=tamA)
      resulta[i] = a[i];
    else
      resulta[i] = ' ';
  } 

  for (int y = 0; y <= tamB; y++)
  {
    resulta[y + tamA+1] = b[y];
  }

  for (int k = 0; k < tamanho; k++)
  {
    cout<< resulta[k]; 
  }

  delete[] resulta;  

  return 0;
}