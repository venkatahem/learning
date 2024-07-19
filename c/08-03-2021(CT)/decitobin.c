#include <stdio.h>

void main()
{
    int a,i,j,n;
    int bin[20],bin1[20];
    printf("Enter a number: ");
    scanf("%d",&a);
    i = 0;
    while(a != 0)
    {
        bin[i] = a%2;
        a = a/2;
        i++;
    }
    n = i;
    printf("\nBinary representation\n");
    j = 0;
    for(i=n-1;i>=0;i--)
    {
        printf("%d",bin[i]);
        bin1[j] = bin[i];
        j++;
    }
    printf("\nEnter the position to toggle: ");
    scanf("%d",&a);
    if(bin1[a-1] == 0)
    {
        bin1[a-1] = 1;
    }
    else if(bin1[a-1] == 1)
    {
        bin1[a-1] = 0;
    }
    printf("\nAfter toggling\n");
    for(i=0;i<n;i++)
    {
        printf("%d",bin1[i]);
    }
}