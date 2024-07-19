#include <stdio.h>
#define sides 3
void triin(int *);
void tritest(int *);

int main()
{
    int tri[sides];
    printf("\nEnter the lengths of 3 sides\n");
    triin(tri);
    tritest(tri);

    return 0;
}
void triin(int *p)
{
    int i;
    for(i=0;i<sides;i++)
    {
        scanf("%d",p+i);
    }
}
void tritest(int *q)
{
    if(*(q+0) == *(q+1) && *(q+0) == *(q+2) && *(q+1) == *(q+2))
    printf("Equilateral triangle");
    else if(*(q+0) != *(q+1) && *(q+0) != *(q+2) && *(q+1) != *(q+2))
    printf("Scalen triangle");
    else if(( *(q+0) == *(q+1) && *(q+2) != *(q+0) && *(q+1) ) || ( *(q+0) == *(q+2) && *(q+1) != *(q+0) && *(q+2) ) )
    printf("Isoseles triangle");
}
