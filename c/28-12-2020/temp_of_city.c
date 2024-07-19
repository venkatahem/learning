#include <stdio.h>
int main()
{
    int temp[5][4];
    int avg[5];
    int i,j,sum=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Enter the temprature for day %d[interval %d]: ",i+1,j+1);
            scanf("%d",&temp[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            sum=sum+temp[i][j];
        }
        avg[i]=sum/4;
        sum=0;
    }
    for(i=0;i<5;i++)
    {
        printf("average temp of day %d is %d\n",i+1,avg[i]);
    }

    return 0;
}