#include <stdio.h>
#include <conio.h>
int main()
{
    int bre;
    int len;
    int area;
    printf("Enter the length: ");
    scanf("%d",&len);
    printf("Enter the breadth: ");
    scanf("%d",&bre);
    area=len*bre;
    printf("%d is area\n",area);
    getch();

    return 0;
}