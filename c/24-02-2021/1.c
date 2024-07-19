#include <stdio.h>
int main()
{
 FILE *f1,*f2;
 char a[100],c;
 int n;
 f1=fopen("file1.txt","r+");
 f2=fopen("file2.txt","r");
 printf("enter the position where contents should be added:");
 scanf("%d",&n);
 fseek(f1,n,0);
 c=getc(f1);
 for(int i=0;!feof(f1);i++)
 {
   a[i]=c;
   c=getc(f1);
 }
 fseek(f1,n,0);
 c=getc(f2);
 while(!feof(f2))
 {
   putc(c,f1);
   c=getc(f2);
 }
 for(int i=0;a[i]!='\0';i++)
 {
   putc(a[i],f1);
 }
 fclose(f1);
 fclose(f2);
 return 0;
}