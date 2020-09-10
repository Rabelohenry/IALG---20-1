#include <iostream>
using namespace std;

struct atleta{
  float parcial;
};

int main(){ 

  atleta *tempos = new atleta[8];

  float menor; 
  
  for (int i = 0; i < 8; i++)
  {
    cin >> tempos[i].parcial;
    if (i == 0)
      menor = tempos[i].parcial;
    else if (tempos[i].parcial<menor)
      menor = tempos[i].parcial;
  }
  cout.precision(1);
  for (int i = 0; i < 8; i++)
  {
    if (tempos[i].parcial>menor){
      cout<<fixed<<(tempos[i].parcial-menor)<<endl;
    }else if (tempos[i].parcial == menor){
      cout<<menor<<endl;
    }
  }

  delete[] tempos;

  return 0;
}