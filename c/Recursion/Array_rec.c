#include <stdio.h>
int array(int);
int z;
int elements[100];
int main()
{
    int n=0;
    printf("The no.of elements: ");
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        printf("Enter the element %d: " ,i+1);
        scanf("%d",&elements[i]);
    }
    array(n);

    return 0;
}
int array(int n)
{
    if(n<z)
    {
        printf("%d ",elements[n]);
        array(n+1);
    }
}