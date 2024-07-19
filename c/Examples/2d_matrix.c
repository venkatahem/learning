#include <stdio.h>
void mat(int p[3][3] );

int main()
{
   int matrix[3][3];
   int i,j;
   mat(matrix);
   for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
           printf("%d  ",*(*(matrix+i)+j));
       }
       printf("\n");
   }

   return 0;
}
void mat(int p[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter the element[%d][%d]: ",i+1,j+1);
            scanf("%d",(*(p+i)+j));
        }
    }
}