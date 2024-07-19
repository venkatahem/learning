#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n,i,sum=0,avg=0;
    printf("Enter the no.of subjects: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter the marks in subject[%d]: ",i+1);
        scanf("%d",(arr+i));
    }
    for(i=0;i<n;i++)
    {
        sum = sum + *(arr+i);
    }
    avg = sum/n;
    printf("\nAverage mark is %d",avg);
    
    return 0;
}