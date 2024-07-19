#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char str[30][30],ch[30],temp[30];
    int i,j,k,n;
    FILE *f1,*f2,*f3;
    f1 = fopen("1.txt","r+");
    f2 = fopen("2.txt","r+");
    for(i=0;!feof(f1);i++)
    {
        fgets(ch,30,f1);
        strcpy(str[i],ch);
    }
    i = i-1;
    for(;!feof(f2);i++)
    {
        fgets(ch,30,f2);
        strcpy(str[i],ch);
    }
    for(i=0;i<8;i++)
    {
        puts(str[i]);
    }
    n = i;
    printf("%d\n",n);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(str[i],str[j])>0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);

            }
        }
    }
    for(i=0;i<8;i++)
    {
        puts(str[i]);
    }
    /*f3 = fopen("3.txt","w");
    for(i=0;i<n;i++)
    {
        strcpy(temp,str[i]);
        fputs(temp,f3);
    }
    printf("\n\nSuccessfully completed\n\n");
    fclose(f1);
    fclose(f2);
    fclose(f3);*/
}