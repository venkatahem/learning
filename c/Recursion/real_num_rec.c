#include <stdio.h>
int real(int);
int n;
int main()
{
    int y=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("\n");
    real(y);
    return 0;
}
int real(int y)
{
    if(y<=n)
    {
        printf("%d  ",y);
        real(y+1);
    }
   
}