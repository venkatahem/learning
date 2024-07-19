#include <stdio.h>

int main()
{
    int arr[10];
    int *p;
    int n,i;
    p=arr;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }
    printf("\nPrinting the elments in reverse without using pointers\n");
    for(i=n-1;i>=0;i--)
    {
        printf("%d  ",arr[i]);
    }
    printf("\nPrinting the elments in reverse using pointers\n");
    for(n;n>0;n--)
    printf("%d  ",*(p+n-1));

    return 0;
}    