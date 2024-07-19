#include <stdio.h>
 int main()
{
    char str[100];
    int i,j,n=0;
    printf("Enter a string:\n");
    gets(str);
    while(str[n]!='\0')
    {
        n++;
    }
    while(i<n)
    {
        if(str[i]==' ' && (str[i+1]==' '|| str[i-1]==' '))
        {
            for(j=i;j<n;j++)
            {
                str[j]=str[j+1];
                n--;
            }
        }
        else
        {
            i++;
        }
        
    }
    printf("%s",str);

    return 0;
}