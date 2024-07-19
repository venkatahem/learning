#include <stdio.h>

int main()
{
    int arr[10];
    int i,j,x;
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(arr[i]>arr[j])
            {
                x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}