#include <iostream>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
  int num=0,pos=0,nega=0;
  double media=0,perPOs,perNEG,soma=0,total=0;
  do{
    cin>>num;
    soma=soma+num;
    if (num >0)
    {
      pos++;
    }else if(num <0){
      nega++;
    }
    total++;
  }while (num!=0);
  media= soma/(total-1);
  perPOs=((total-1)/100)*pos;
  perNEG=((total-1)/100)*nega;

  cout<<media<<endl<<pos<<endl<<nega<<endl<<perPOs<<endl<<perNEG;

  return 0;
}
