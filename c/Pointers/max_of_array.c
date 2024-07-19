#include <stdio.h>
int max(int * ,int ,int *);
int main()
{
    int array[100];
    int n,ma,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&array[i]);
    }
    ma=array[0];
    max(array, n, &ma);
    printf("%d",ma);

    return 0;
}
int max(int array[],int n,int *ma)
{
    *ma=array[0];
    for(int i=1;i<n;i++)
    {
        if(*ma<array[i])
        {
            *ma=array[i];
        }
    }
}