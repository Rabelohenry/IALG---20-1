#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
  int codEstad,codProd,valor;
  float toneladas,imposto;
  
  cin>>codProd>>codEstad>>toneladas;

  if (codProd>=10 && codProd<=20){
    valor = 100;
  }else if(codProd>=21 && codProd<=30){
    valor=250;
  }else if(codProd>=31 && codProd<=40){
    valor=340;
  }
  switch (codEstad)
  {
  case 1:
    imposto = 1.35;
    break;
  case 2:
    imposto = 1.25;
    break;
  case 3:
    imposto = 1.15;
    break;
  case 4:
    imposto = 1.05;
    break;
  case 5:
    imposto = 1;
    break;  
  default:
    break;
  }
  

  cout<<toneladas*1000<<endl;
  cout<<(toneladas*1000)*valor<<endl;
  cout<<(((toneladas*1000)*valor)*imposto)-((toneladas*1000)*valor)<<endl;
  cout<<((toneladas*1000)*valor)*imposto<<endl;


  return 0;
}