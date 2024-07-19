#include <stdio.h>
int main()
{
  FILE *f1;
  int id,total[10]={0},m1,m2,m3,m4,m5,i=0,j,p,q;
  f1=fopen("file1.txt","r");
  char name[20];
  fscanf(f1,"%d %s %d %d %d %d %d",&id,name,&m1,&m2,&m3,&m4,&m5);
  while(i<10)
  {
    total[i] = total[i] + m1 + m2 + m3 + m4 + m5;
    fscanf(f1,"%d %s %d %d %d %d %d",&id,name,&m1,&m2,&m3,&m4,&m5);
    ++i;
  }
  q=total[0];
  for(j=0;total[j]!='\0';j++)
  {
    if(total[j]>q)
   {
    q=total[j];
    p=j;
   }
  }
 fseek(f1,0,0);
 for(int k=0;k<=p;k++)
 {
   fscanf(f1,"%d %s %d %d %d %d %d",&id,name,&m1,&m2,&m3,&m4,&m5);
 }
 printf("\nHighest score is secured by:\nID:%d\nName:%s\nMarks:%d,%d,%d,%d,%d\nTotal:%d",id,name
 ,m1,m2,m3,m4,m5,q);
 fclose(f1);
 return 0;
}