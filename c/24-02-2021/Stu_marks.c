#include <stdio.h>
#include<string.h>
struct stud
{
 char name[15];
 int reg,mark[3],tot,rank;
};
int main() 
{
 char a[3][15],temp[15];
 int t,k=0;
 struct stud st[3];
 for(int i=0;i<3;i++)
 {
 printf("\nSTUDENT %d details:",i+1);
 printf("\nenter the name of the student %d:",i+1);
 scanf("%s",st[i].name);
 printf("\nenter the reg no.");
 scanf("%d",&st[i].reg);
 printf("\nenter three marks:");
 for(int j=0;j<3;j++)
 {
 scanf("%d",&st[i].mark[j]);
 }
 st[i].tot=st[i].mark[0]+st[i].mark[1]+st[i].mark[2];
 }
 for(int i=0;i<3;i++)
 {
 strcpy(a[i],st[i].name);
 }
 for(int i=1;i<=3;i++)
 {
 for(int j=0;j<2;j++)
 {
 if(st[j].name[0] > st[j+1].name[0])
 {
 strcpy(temp,st[j].name);
 strcpy(st[j].name,st[j+1].name);
 strcpy(st[j+1].name,temp);
 t=st[j].reg;
 st[j].reg=st[j+1].reg;
 st[j+1].reg=t;
 while(k<3)
 {
 t=st[j].mark[k];
 st[j].mark[k]=st[j+1].mark[k];
 st[j+1].mark[k]=t;
 k++;
 }
 }
 }
 }
 for(int i=0;i<3;i++)
 {
 printf("\nSTUDENT %d:",i+1);
 printf("\nName:%s",st[i].name);
 printf("\nReg no.:%d",st[i].reg);
 printf("\nMarks:");
 for(int j=0;j<3;j++)
 {
 printf("%d,",st[i].mark[j]);
 }
 printf("\nTotal:%d",st[i].tot);
 }
 return 0;
}