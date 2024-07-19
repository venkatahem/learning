#include <stdio.h>

int main()
{
    int *a;
    int i;

    for (i = 0; i < 8; i++)
    {
        *(a + i) = i * 4;
    }

    return 7;
}