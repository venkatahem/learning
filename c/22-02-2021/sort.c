#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char str[30],*st[30];
    int i,j,k,temp,n,a[30],b[30];
    FILE *f1,*f2,*f3;
    f1 = fopen("1.txt","r");
    f2 = fopen("2.txt","r");
    for(i=0;!feof(f1);i++)
    {
        fgets(str,30,f1);
        st[i] = (char*)malloc((sizeof(str)+1)*sizeof(char));
        strcpy(st[i],str);
    }
    i = i-1;
    for(;!feof(f2);i++)
    {
        fgets(str,30,f2);
        st[i] = (char*)malloc((sizeof(str)+1)*sizeof(char));
        strcpy(st[i],str);
    }
    n = i;
    for(j=0;j<n;j++)
    {
        strcpy(str,st[j]);
        a[j] = str[0] - 'a';
    }
    for(j=0;j<n;j++)
    {
        b[j] = a[j];
    }
    for(j=0;j<n-1;j++)
    {
        for(k=j+1;k<n;k++)
        {
            if(b[j] > b[k])
            {
                temp = b[j];
                b[j] = b[k];
                b[k] = temp;
            }
        }
    }
    f3 = fopen("3.txt","w");
    for(k=0;k<n;k++)
    {
        for(j=0;j<n;j++)
        {
            if(b[k] == a[j])
            {
                strcpy(str,st[j]);
                fputs(str,f3);
            }
        }
    }
    printf("\nSuccessfully completed\n\n");
}