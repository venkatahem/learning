#include <stdio.h>

void main()
{
    char x[30];
    int i,k,p;
    printf("Enter a string:\n");
    fgets(x,sizeof(x),stdin);
    printf("\nEnter the length of substring to be printed: ");
    scanf("%d",&k);
    printf("Enter the position: ");
    scanf("%d",&p);
    for(i=p-1;i<(p-1)+k;i++)
    {
        printf("%c",x[i]);
    }
}