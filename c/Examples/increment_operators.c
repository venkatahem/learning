#include <stdio.h>

int main()
{
    int x=3,y;
    y = ++x + x++;
    printf("%d,%d",y,x);

    return 0;
}