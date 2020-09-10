#include <iostream>
#include <string>
using namespace std;

string ordena(int y)
{
    int x;
    string final;
    if (y > 0)
    {
        cin >> x;
        if (y == 1)
            final = ordena(y - 1) + to_string(x);
        else
            final = ordena(y - 1) + " " + to_string(x);
    }

    return final;
}

int main()
{
    int y;

    cin >> y;
    cout << ordena(y) << endl;

    return 0;
}
