#include <stdio.h>
#include "add.h"

int main()
{
    int a,b;
    printf("Enter two numbers to add:\n");
    scanf("%d%d",&a,&b);
    printf("%d",add(a,b));

    return 0;
}