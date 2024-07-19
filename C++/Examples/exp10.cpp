#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 0;
    int in, i, num;
    string str;

    cin >> in;
    getchar();

    for (i = 0; i < in; i++)
    {
        cin >> str;
        num = 0;
        if (((str[1] == '+') && (str[2] == '+')) || ((str[0] == '+') && (str[1] == '+')))
        {
            x = x + 1;
        }
        else if (((str[1] == '-') && (str[2] == '-')) || ((str[0] == '-') && (str[1] == '-')))
        {
            x = x - 1;
        }
        else if ((str[2] >= '0') && (str[3] <= '9'))
        {
            for (int j = 2; str[j] != '\0'; j++)
            {
                num = (num * 10) + (str[j] - '0');
            }
            if (str[1] == '+')
            {
                x = x + num;
            }
            else if (str[1] == '-')
            {
                x = x - num;
            }
        }
    }

    cout << x << endl;

    return 7;
}