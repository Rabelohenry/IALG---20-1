#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int n;
  string pil1 = "", pil2 = "";

  cin >> n >> pil1;

  float km1[n], km2[n];

  for (int i = 0; i < n; i++)
  {
    cin >> km1[i];
  }

  cin >> pil2;

  for (int j = 0; j < n; j++)
  {
    cin >> km2[j];
  }

  for (int k = 0; k < n; k++)
  {
    if (km1[k] > km2[k])
    {
      cout << pil2 << " ";
    }
    else
    {
      cout << pil1 << " ";
    }
  }
  cout << endl;

  for (int l = 0; l < n; l++)
  {
    if ((km1[l] - km1[l - 1]) > (km2[l] - km2[l - 1]))
    {
      cout << pil2 << " ";
    }
    else if (l == 0)
    {
      if (km1[0] > km2[0])
      {
        cout << pil2 << " ";
      }
      else
      {
        cout << pil1 << " ";
      }
    }
    else
    {
      cout << pil1 << " ";
    }
  }
  return 0;
}