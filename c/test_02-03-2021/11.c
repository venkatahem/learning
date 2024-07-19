#include<stdio.h>
#include<string.h>
int main()
{
FILE *f;
f=fopen("file","w");
struct details
{ 
    char name[10];
    int mark[3],total,rank,id;
}a[20],tmp;

int size,j;
printf("enter the number of students:");
scanf("%d",&size);
for(int i=0;i<size;i++){
printf("enter student %d details\n",i+1);
printf("enter reg.no:");
scanf("%d",&a[i].id);
printf("name:");
scanf("%s",a[i].name);
printf("enter the marks:");
scanf("%d%d%d%d",&a[i].mark[0],&a[i].mark[1],&a[i].mark[2],&a[i].mark[3]);
a[i].total=a[i].mark[0]+a[i].mark[1]+a[i].mark[2]+a[i].mark[3];
}
for(int i=0;i<size;i++)
for(int j=i+1;j<size;j++)
{
   if(a[i].total<a[j].total)
    {
       tmp=a[i];
       a[i]=a[j];
       a[j]=tmp;
    }
}

for(int i=0;i<size;)
{ 
   if(a[i].total==a[i+1].total)
   {  
       j=i;
        while(a[j].total==a[j+1].total)
            {
               a[j].rank=i+1;
               a[j+1].rank=i+1;
               j++;
            }
     i=j+1;
    }
    else
      {
         a[i].rank=i+1;
         i++; 
      }
} 
 for(int i=0;i<size;i++)
 fprintf(f,"name:%s mark 1:%d mark 2:%d mark3:%d  mark4:%d total:%d rank:%d\n",a[i].name,a[i].mark[0],a[i].mark[1],a[i].mark[2],a[i].mark[3],a[i].total,a[i].rank);
 fclose(f);
}