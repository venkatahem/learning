#include <stdio.h>
int main()
{
    int mata[10][10];
    int col,row,i,j,ele,k=0;
    printf("Enter no.of rows and columns\n");
    scanf("%d %d",&row,&col);
    if(row==col)
    {
        printf("Enter the elements\n");
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                printf("Enter the element A[%d][%d]: ",i+1,j+1);
                scanf("%d",&mata[i][j]);
            }
        }
         printf("\nEntered matrix: \n");
        for (i = 0; i < row; ++i)
         for (j = 0; j < col; ++j) 
         {
            printf("%d  ", mata[i][j]);
            if (j == col - 1)
                printf("\n");
         }
        ele=mata[0][0];
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(i==j)
                {
                   if(mata[i][j]==ele)
                   {
                       k=1;
                   }
                }
                if(i!=j)
                {
                    if(mata[i][j]!=0)
                    {
                        k=0;
                    }
                }
            }
        }
        if(k==1)
        printf("Scalar Matrix\n");
        else
        printf("Not a Scalar Matrix");

    }
    else
    {
        printf("Not a square matrix\n" );
    }
    
    return 0;
}