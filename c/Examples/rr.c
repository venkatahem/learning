#include<stdio.h>

void findwait(int n,int b[],int w[],int q)
{
  int t=0;
  int temp[n];
  for(int i=0;i<n;i++)
  {
    temp[i]=b[i];  
  }
  while(1)
  {
  int f=1;
  {
    for(int i=0;i<n;i++)
    {
     
    if(temp[i]>0)
    {
    f=0;
      if(temp[i]>q)
      {
        t+=q;
        temp[i]=temp[i]-q;
      
      }
      else
      {
         t+=temp[i];
         w[i]=t-b[i];
         temp[i]=0;
      }
    }
    }
    if(f)
     break;
  }
 }
}

void findturn(int n,int w[],int b[],int t[])
{
  for(int i=0;i<n;i++)
  {
    t[i]=w[i]+b[i];
  }
  
}
int main()
{
  int n;
  int q=2;
  printf("\nEnter number of processes:");
  scanf("%d",&n);
  int p[n],b[n],w[n],t[n];
  for(int i=0;i<n;i++)
  {
    p[i]=i+1;
    printf("\nEnter burst time for p%d:",i+1);
    scanf("%d",&b[i]);
  }
  findwait(n,b,w,q);
  findturn(n,w,b,t);
  int avg = 0;
  printf("process\tburst_time\twait_time\tturn_around_time\n");
  for(int i = 0;i < n;++i)
  {
  avg += w[i];
  printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],b[i],w[i],t[i]);
  }
    avg /= n;
    printf("\nAverage waiting time:%d\n",avg);

}
