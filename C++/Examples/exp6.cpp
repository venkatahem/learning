#include <iostream>

using namespace std;

int main()
{
    long long int i;

    /*
    for (i = 0; i < 100; i++)
    {
        cout << i << endl;
    }
    */

    i = 1;

    while (i < 1000000000000000000)
    {
        cout << i << endl;
        i = i * 10;
    }

    return 7;
}