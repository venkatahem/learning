#include <stdio.h>

int main()
{
    char c;
    FILE *f1 , *f2;
    f1 = fopen("1.txt","r");
    f2 = fopen("2.txt","w");
    c = getc(f1);
    while(c!=EOF)
    {
        putc(c,f2);
        c = getc(f1);
    }
    fclose(f1);
    fclose(f2);

    return 0;
}