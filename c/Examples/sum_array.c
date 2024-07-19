#include <stdio.h>
int sum(int *p,int l);

int main()
{
  int arr[20];
  int i,n=0,s;
  printf("\nEnter the size of array: ");
  scanf("%d",&n);
  printf("\nEnter the elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",(arr+i));
  }
  printf("\nElements in the array\n");
  for(i=0;i<n;i++)
  {
    printf("%d  ",*(arr+i));
  }  
  s=sum(arr,n);
  printf("\n%d is the of sum of elements in the array\n",s);
  
  return 0;  
}
int sum(int *p,int l)
{
  static int s=0;
  static int i=0;
  if(i<l)
  {
    s = s + *(p+i);
    i++;
    sum(p,l);
  }
  else
  {
    return s;
  }
 }     