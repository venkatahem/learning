#include<stdio.h>
int main()
{
FILE *f1,*f2;
char a,b;
int f=0;
f1=fopen("file1.txt","r");
f2=fopen("file2.txt","r");
a=getc(f1);
b=getc(f2);
while( a!=EOF || b!=EOF)
{
if(a==b)
f=1;
else
{
f=0;
break;
}
a=getc(f1);
b=getc(f2);
}if(f==1)
printf("\nBoth files are same");
else
printf("\nFiles are not same");
return 0;
}