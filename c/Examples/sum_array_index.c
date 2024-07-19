#include <stdio.h>

int main()
{
    int len;
    int i,j,k;
    int temp,sum;
    int array[100];
    printf("Enter the size of array: ");
    scanf("%d",&len);
    printf("Enter the required sum: ");
    scanf("%d",&sum);
    printf("Enter elements:\n");
    for(i=0;i<len;i++)
    {
        scanf("%d",&array[i]);
    }
    i = 0;
    while(i < len)
    {
        temp = 0;
        for(j=i;j<len;j++)
        {
            temp = temp + array[j];
            if(temp == sum)
            {
                break;
            }

        }
        if(temp == sum)
        {
            break;
        }
        i++;
    }
    printf("%d %d",i+1,j+1);

    return 0;
}