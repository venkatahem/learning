#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char str[30];
    f = fopen("wrt.txt","w+");
    if(f == NULL)
    {
        puts("Can't open file");
        exit(0);
    }
    
}
