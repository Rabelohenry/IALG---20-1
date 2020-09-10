#include <iostream>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
  int entrada,i=0,j=0;

  cin>>entrada;

  while (i!=entrada)
  {
    if (i==0)
    {
      cout<<"@";
    }
    
    while (j!=i)
    {
      if (j==0)
      {
        cout<<"@";
      }
      
      if (j%2!=0)
      {
        cout<<"@";
      }
      
      if (j%2==0){
        cout<<"#";
      }
      j++;
    }
    if (j==i)
    {
      cout<<endl;
    }
    
    j = 0;
    i++;
  }
  
  
  

  return 0;
}
