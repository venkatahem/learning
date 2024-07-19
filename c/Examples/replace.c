#include <stdio.h>

int main()
{
    int a,b,c=1,rem,x,i;
    printf("Enter a integer: ");
    scanf("%d",&a);
    printf("Enter the position for inserting zero(readng from last): ");
    scanf("%d",&b);
    for(i=0;i<b-1;i++)
    {
        c = c*10;
    }
    i=0;
    x = a;
    while(i<b)
    {
        rem = x%10;
        x = x/10;
        rem = rem*c;
        i++;
    }
    a = a-rem;
    printf("\nAfter making index %d as zero : %d",b,a);
    return 0;
}