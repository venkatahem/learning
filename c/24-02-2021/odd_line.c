#include <stdio.h>
#include <string.h>

void main()
{
    char str[30],a[30][30];
    int i,j,k;
    FILE *f1,*f2;
    f1 = fopen("1.txt","r+");
    f2 = fopen("2.txt","w+");
    for(i=0;!feof(f1);i++)
    {
        fgets(str,30,f1);
        strcpy(a[i],str);
    }
    j = i;
    for(i=0;i<j;i++)
    {
        if((i+1)%2 != 0)
        {
            fprintf(f2,"%s",a[i]);
        }
    }
}