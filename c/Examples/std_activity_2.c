#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void five_three(int x)
{
    if (x % 3 == 0 && x % 5 == 0)
    {
        printf("FizzBuzz");
    }
    else
    {
        printf("%d", x);
    }
}

void five(int x)
{
    int n = x;
    if (x % 5 == 0)
    {
        printf("Buzz");
    }
    else
    {
        five_three(n);
    }
}

void three(int x)
{
    int n = x;
    if (x % 3 == 0)
    {
        printf("Fizz");
    }
    else
    {
        five(n);
    }
}

void prime(int x)
{
    int i;
    int n = x;
    int flag = 1;
    for (i = 2; i <= x / 2; ++i)
    {
        if (x % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Prime");
    }
    else
    {
        three(n);
    }
}

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int i;
    int n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            printf("1");
        }
        else
        {
            prime(i);
        }
    }

    return 0;
}
