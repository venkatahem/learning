#include <stdio.h>
int fun();
static int i=2; 
int main()
{
    i++;
    printf("%d",i);
    fun(i);
    printf("%d",i);

    return 0;
}
int fun()
{
    i++;
    printf("%d",i);
}