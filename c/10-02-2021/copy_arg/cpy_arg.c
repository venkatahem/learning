#include<stdio.h>
#include <conio.h>
int main(int argc,char *argv[])
{
 FILE *f1,*f2;
 int ch;
 if(argc!=3)
 {
    printf("Invalide numbers of arguments.");
    return 0;
 }
 f1=fopen(argv[1],"r");
 if(f1==NULL)
 {
    printf("Can't find the source file.");
    return 0;
 }
 f2=fopen(argv[2],"w");
 if(f2==NULL)
 {
    printf("Can't open target file.");
    fclose(f1);
     return 0;
 }
 ch = getc(f1);

 while(ch != EOF)
 {
    putc(ch,f2);
    ch = getc(f1);
 }

   printf("\nFile copied\n");
    fclose(f1);
    fclose(f2);
    getch();
    return 0;
}
