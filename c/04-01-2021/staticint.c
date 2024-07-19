#include<stdio.h>
int main()
{
    printf("Program to demonstate static storage class \n");
    for(int i=1 ; i<5 ; i++)
    {
        static int b=5;
        int a=10;
        b++;
        a++;
        printf("Value of static int b: %d\n",b);
        printf("Vale of a: %d\n",a);
    }
    return 0;
}