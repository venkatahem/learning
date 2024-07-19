#include<stdio.h>
int rec(int a[],int);
int main()
{
int a[50],n,o=0,e=0,or;
printf("enter the size of the array:");
scanf("%d",&n);
printf("\nenter the array elements:");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
if(a[i]%2==0)
e++;
}
or=rec(a,n-1);
printf("\nthe number of even elements=%d",e);
printf("\nthe number of odd elements = %d",or);
return 0;
}
int rec(int a[],int n)
{
static int odd=0;
 if(a[n]%2!=0 && n>=0)
 {
 odd++;
 rec(a,n-1);
 }
 else if(n>=0)
 rec(a,n-1);
 else
 return odd;
}