#include <iostream>
using namespace std;

long int power(long int n, long int x)
{
    if (x < 1)
    {
        return 1;
    }
    else
    {
        return n * power(n, x - 1);
    }
}

int main()
{
    long int num;
    long int pow;

    cout << "\n\nEnter base: ";
    cin >> num;
    cout << "\nEnter index: ";
    cin >> pow;

    cout << "\n"
         << num << " to the power of " << pow << " is " << power(num, pow) << "\n\n";

    return 7;
}