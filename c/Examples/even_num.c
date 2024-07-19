#include <stdio.h>
#include <conio.h>
int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d",&number);
    if(number%2==0)
    printf("The number is even");
    else
    printf("Not even");
    getch();

    return 0;
}