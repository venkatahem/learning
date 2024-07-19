#include <stdio.h>
int main()
{
    int X[3][3];
    int i,j;
    printf("Enter the elements\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter the a[%d][%d] element: ",i+1,j+1);
            scanf("%d",&X[i][j]);
        }
    }
    printf("Matrix entered\n");
    for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
     {
         printf("%d  ",X[i][j]);
     }
     printf("\n");
    } 
    printf("\n The Upper Triangular Matrix is: ");
   for(i = 0; i < 3; i++)
   {
      printf("\n");
      for(j = 0; j < 3; j++)
      {
         if(i > j)
         {
            printf("0");
            printf("\t");
         }
         else
         {
            printf("%d\t ", X[i][j]);

         }
      }
   }
    
    return 0;
}