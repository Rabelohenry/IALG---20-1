#include <iostream>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
  int num1,num2;
  int i =1;
  float resto = 1;
    cin>>num1>>num2;
  
  while (resto!=0)
  {
    resto= (num1*i)%num2;
    i++;
  }
  cout<<num1*(i-1);

  return 0;
}
