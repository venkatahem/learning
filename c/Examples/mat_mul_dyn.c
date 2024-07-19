#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *a,*b,*c;
    int ar,br,ac,bc,i,j,k,sum;
    printf("Enter the no.of rows and columns for matrix 1:\n");
    scanf("%d %d",&ar,&ac);
    printf("Enter the no.of rows and columns for matrix 2:\n");
    scanf("%d %d",&br,&bc);
    if(ac != br)
    {
        printf("\nMatrix multiplication is not possible\n");
    }
    else
    {
        a = (int*)malloc(ar*ac*sizeof(int));
        b = (int*)malloc(br*bc*sizeof(int));
        c = (int*)malloc(ar*bc*sizeof(int));
        printf("Enter the elements of matrix 1:\n");
        for(i=0;i<ar;i++)
        {
            for(j=0;j<ac;j++)
            {
                scanf("%d",((a+i)+j));
                printf("\nEntered: %d\n\n",*((a+i)+j));
            }
        }
        printf("Enter the elements of martix 2:\n");
        for(i=0;i<br;i++)
        {
            for(j=0;j<bc;j++)
            {
                scanf("%d",((b+i)+j));
                printf("\nEntered: %d\n\n",*((b+i)+j));
            }
        }
    for(i=0;i<ar;i++)
    {
        for(j=0;j<bc;j++)
        {
            sum = 0;
            for(k=0;k<ac;k++)
            {
                sum = sum + (*((a+i)+k)) * (*((b+k)+j)) ;
            }
            *((c+i)+j) = sum;
        }
    }
    for(i=0;i<ar;i++)
    {
        for(j=0;j<bc;j++)
        {
            printf("%d  ",*((c+i)+j));
        }
        printf("\n");
    }
    }
}