#include <stdio.h>
int main()
{
    int n,m;
    printf("Enter n: ");
    scanf("%d",&n);
    m=n%10;
    printf("%d\n",m);
    printf("%d",n/10);

    return 0;
}