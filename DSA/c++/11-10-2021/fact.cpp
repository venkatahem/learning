#include <iostream>
using namespace std;

long int fact(long int n)
{
    if (n < 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    long int num;

    cout << "\n\nEnter a number: ";
    cin >> num;
    cout << "\nFactorial of " << num << " is " << fact(num) << "\n\n";

    return 7;
}