#include <iostream>
using namespace std;

int var = 9; //Global

void exp()
{
    cout << var << "\n";
}

void exp1()
{
    int var = 7; //Local
    cout << var;
}

int main()
{
    exp();
    exp1();
    return 7;
}