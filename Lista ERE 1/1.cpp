#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
  float preco;
  cin >> preco;

  if (preco < 50){
    preco = preco * 1.05;
    cout << preco << endl;
  }else if (preco >= 50 && preco <= 100){
    preco = preco * 1.10;
    cout << preco << endl;
  }else if(preco > 100){
    preco = preco * 1.15;
    cout << preco << endl;
  }
  
  if(preco < 80){
    cout << "Barato";
  }else if (preco >= 80 && preco <= 120){
    cout << "Normal";
  }else if(preco > 120 && preco <= 200){
    cout << "Caro";
  }else if (preco > 200){
    cout << "Muito caro";
  }

  return 0;
}