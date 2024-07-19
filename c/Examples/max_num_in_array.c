#include <stdio.h>
int main()
{
    int array[100];
    int n,i,max;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&array[i]);
    }
    max=array[0];
    for(i=0;i<n;i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
    }
    printf("\n%d is the largest number",max);

    return 0;
}