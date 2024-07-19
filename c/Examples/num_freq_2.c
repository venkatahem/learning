#include <stdio.h>

int main()
{
    int count[10],i;
    long long int x,y;
    for(i=0;i<10;i++)
    {
        count[i] = 0;
    }
    printf("Enter a number: ");
    scanf("%lld",&x);
    while(x!=0)
    {
        y = x%10;
        count[y] = count[y] + 1;
        x = x/10;
    }
    printf("Frequency\n");
    for(i=0;i<10;i++)
    {
        if(count[i] == 0)
        {
            continue;
        }
        else
        {
            printf("%d ==> %d\n",i,count[i]);
        }
    }

    return 0;
}