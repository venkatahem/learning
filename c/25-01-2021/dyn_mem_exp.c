#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *c;
    int *i;
    float *f;
    c=(char*)malloc(sizeof(char));
    i=(int*)malloc(sizeof(int));
    f=(float*)malloc(sizeof(float));
    printf("Enter a character: ");
    scanf("%c",c);
    printf("Enter a integer: ");
    scanf("%d",i);
    printf("Enter a float value: ");
    scanf("%f",f);
    printf("Entered:\n%c is the character\n%d is the int\n%f is the float value\n",*c,*i,*f);

    return 0;
}