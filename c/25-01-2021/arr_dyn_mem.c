#include <stdio.h>
#include <stdlib.h> 
int *array(int *,int);

int main()
{
    int *arr1,*arr2;
    int a,b,c,i,j=0;
    printf("Enter the size of 1st array: ");
    scanf("%d",&a);
    arr1=(int*)malloc(a*sizeof(int));
    array(arr1,a);
    printf("Enter the size of 2nd array: ");
    scanf("%d",&b);
    arr2=(int*)malloc(b*sizeof(int));
    array(arr2,b);
    c=a+b;
    arr1=(int*)realloc(arr1,c*sizeof(int));
    i=a;
    while(i<c)
    {
        *(arr1+i) = *(arr2+j);
        i++;
        j++;
    }
    printf("Ater concatenation:\n");
    for(i=0;i<c;i++)
    {
        printf("%d  ",*(arr1+i));
    }

    return 0;
}
int *array(int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the element[%d]: ",i+1);
        scanf("%d",(p+i));
    }
    return p;
}
