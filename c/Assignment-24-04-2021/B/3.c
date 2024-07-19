#include <stdio.h>

void main()
{
    int mark[3];
    int avg, i;
    printf("Enter the marks in three subjects:\n");
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &mark[i]);
    }
    avg = 0;
    for (i = 0; i < 3; i++)
    {
        avg = avg + mark[i];
    }
    avg = avg / 3;
    printf("\nAverage marks = %d", avg);
    if (avg >= 90)
    {
        printf("\nA - Grade\n");
    }
    else if (avg >= 75 && avg < 90)
    {
        printf("\nB - Grade\n");
    }
    else if (avg >= 60 && avg < 75)
    {
        printf("\nC - Grade\n");
    }
    else if (avg >= 50 && avg < 60)
    {
        printf("\nD - Grade\n");
    }
    else if (avg < 50)
    {
        printf("\nFail!!\n");
    }
}