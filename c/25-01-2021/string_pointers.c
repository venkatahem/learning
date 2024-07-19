#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[20], *ptr[20];
    int n,i;
    printf("Enter the number of strings to be entered: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the string:\n");
        scanf("%s",arr);
        ptr[i]=(char*)malloc((strlen(arr)+1)*sizeof(char));
        strcpy(ptr[i],arr);
    }
    for(i=0;i<n;i++)
    {
        printf("\n'%s' is the string%d and %p is the adress",ptr[i],i+1,&(ptr[i]));
    }

    return 0;
}
