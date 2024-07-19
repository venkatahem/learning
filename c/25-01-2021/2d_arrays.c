#include <stdio.h>

int main()
{
    int arr[20][20];
    int row,col,i,j;
    printf("Enter the no.of rows and columns:\n");
    scanf("%d%d",&row,&col);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Enter the element[%d][%d]: ",i+1,j+1);
            scanf("%d",(*(arr+i)+j));
        }
    }
    printf("Entered elements\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d  ",*(*(arr+i)+j));
        }
        printf("\n");
    }

    return 0;
}