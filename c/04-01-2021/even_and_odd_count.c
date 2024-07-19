#include <stdio.h>
int eveodd(int,int);
int main()
{
    int a=1;
    int b=1000;
    eveodd(a,b);

    return 0;
}
int eveodd(int a,int b)
{
    int even=0;
    int odd=0;
    int i;
    for(i=a;i<b;i++)
    {
        if(i%2==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("\n%d is the count of even numbers\n%d is th count off odd numbers\n",even,odd);
}