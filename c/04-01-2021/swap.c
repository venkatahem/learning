#include <stdio.h>
int swap(int,int);
int main()
{
    int a;
    int b;
    printf("Enter a:");
    scanf("%d",&a);
    printf("Enter b:");
    scanf("%d",&b);
    printf("----------* Before Swapping *----------\n");
    printf("             a=%d and b=%d             \n",a,b);
    swap(a,b);
    printf("\nBut in the main functon the values a and b remains same\n");
    printf("as we cannot return two values from a function");

    return 0;
}
int swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("----------* After Swapping *----------\n");
    printf("             a=%d and b=%d            \n",a,b);
    return;
}