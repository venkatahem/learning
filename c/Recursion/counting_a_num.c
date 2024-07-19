#include <stdio.h>
int count(int);
int main()
{
    int z;
    int x=0;
    printf("Enter the number: ");
    scanf("%d",&z);
    if(z==0)
    {
        printf("No.of digits is 1");
    }
    else
    {
    x=count(z);
    printf("There is/are %d digit/s in the entered number",x);
    }
    return 0;
}
int count(int z)
{
    static int x=0;
    if(z!=0)
    {
        x++;
        count(z/10);
    }
    return x;
}