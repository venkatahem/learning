#include <stdio.h>

int main()
{
    int a;
    float b;
    char c;
    void *ptr;
    printf("Enter a character: ");
    scanf("%c",&c);
    printf("Enter a integer: ");
    scanf("%d",&a);
    printf("Enter a float value: ");
    scanf("%f",&b);
    ptr=&a;
    printf("%d is the integer\n",*((int*)ptr));
    ptr=&b;
    printf("%f is the float\n",*((float*)ptr));
    ptr=&c;
    printf("%c is the character\n",*((char*)ptr));

    return 0;
}