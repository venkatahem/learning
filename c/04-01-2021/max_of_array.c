#include <stdio.h>
int max(int);
int ma;
int array[100];
int main()
{
    int n,m;
    printf("Enter the no.of elements in the array: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&array[i]);
    }
    ma=array[0];
    m=max(n);
    printf("%d is max",m);

    return 0;
}
int max(int n)
{
    for(int i=1;i<n;i++)
    {
      if(ma<array[i])
      {
          ma=array[i];
      }
    }
    return ma;
}