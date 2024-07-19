#include <stdio.h>

int main()
{
    int a[10][10];
    int b[10][10];
    int c[10][10];
    int ar,ac;
    int br,bc;
    int i,j,k,sum;
    printf("Enter the size of matrix\n");
    scanf("%d%d",&ar,&ac);
    printf("Enter a %d X %d matrix\n",ar,ac);
    for(i=0;i<ar;i++)
    {
        for(j=0;j<ac;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the size of matrix\n");
    scanf("%d%d",&br,&bc);
    printf("Enter a %d X %d matrix\n",br,bc);
    for(i=0;i<br;i++)
    {
        for(j=0;j<bc;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<ar;i++)
    {
        for(j=0;j<bc;j++)
        {
            c[i][j] = 0;
            for(k=0;k<ac;k++)
            {
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<ar;i++)
    {
        for(j=0;j<bc;j++)
        {
            printf("%d  ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}