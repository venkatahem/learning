#include <stdio.h>

int main()
{
    int count[10] = {0},i;
    int x,y;
    printf("Enter a number: ");
    scanf("%ld",&x);
    while(x != 0)
    {
        y = x%10;
        for(i = 0;i<10;i++)
        {
            if(y == i)
            {
                count[i] = count[i] + 1;
                break;
            }
        }
        x = x/10;
    }
    printf("\nFrequency of the digits:\n");
    for(i=0;i<10;i++)
    {
        printf("%d ==> %d\n",i,count[i]);
    }

    return 0;
}