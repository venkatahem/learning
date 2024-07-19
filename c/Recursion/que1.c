#include <stdio.h>
int fun(int);
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    fun(n);

    return 0;
}
int fun(int n)
{
    int i=0;
    if(n>1)
    {
        fun(n-1);
    }
    for(i=0;i<n;i++)
    {
        printf(" * ");
    }
}