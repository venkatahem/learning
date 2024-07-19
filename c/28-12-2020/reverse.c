#include <stdio.h>
int copy(int);
int main()
{
    int a,y=0;
    printf("Enter a number to copy\n");
    scanf("%d",&a);
    y=copy(a);
    printf("%d is the reversed number\n",y);

    return 0;
}
int copy(int a)
{
   int x,rev=0,n;
   x=a;
   while(x!=0)
   {
       n=x%10;
       rev=rev*10+n;
       x=x/10;
   }
   return rev;

}