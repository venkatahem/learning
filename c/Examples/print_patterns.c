#include <stdio.h>
#include <conio.h>

int main()
{
    int i;
    char a,b;
    for(a='E';a>='A';a--)
    {
        for(b='E';b>=a;b--)
        {
            printf("%c",b);
        }
        printf("\n");
    }
    getchar();

    return 0;
}