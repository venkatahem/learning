#include <stdio.h>
void mat(int p[3][3]);
void add(int x[3][3], int y[3][3]);

int main()
{
   int matrix1[3][3],matrix2[3][3];
   int i,j;
   printf("\nMatrix 1\n");
   mat(matrix1);
   printf("\nMatrix 2\n");
   mat(matrix2);
   printf("\nAddition of two matrices\n");
   add(matrix1,matrix2);

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
    for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
           printf("%d  ",*(*(p+i)+j));
       }
       printf("\n");
   }
}
void add(int x[3][3], int y[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d  ",*(*(x+i)+j) + *(*(y+i)+j));
        }
        printf("\n");
    }
}