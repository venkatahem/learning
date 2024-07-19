#include <stdio.h>
#include <stdlib.h>
void reverse(int *,int);

int main()
{
    int *arr;
    int n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter the element[%d]: ",i+1);
        scanf("%d",(arr+i));
    }
    reverse(arr,n);

    return 0;
}
void reverse(int *p, int n)
{
    int i;
    i=n-1;
    printf("Array in reverse order:\n");
    for(i;i>=0;i--)
    {
        printf("%d  ",*(p+i));
    }
}