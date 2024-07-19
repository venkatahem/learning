#include <stdio.h>
void binary(int);
int main()
{
    int n;
    printf("Enter an number to convert it to binary:\n");
    scanf("%d",&n);
    printf("Binary form of %d is:\n",n);
    binary(n);

    return 0;
}
void binary(int m)
{
    if(m!=0)
    {
        binary(m/2);
        printf("%d",m%2);
    }    
    
}