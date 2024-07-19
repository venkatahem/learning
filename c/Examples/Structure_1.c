#include <stdio.h>

typedef struct
{
    int eno;
    char ena[20];
    float esal;
} STU;

int main()
{
    STU e;
    printf("Enter Employee name\n");
    fgets(e.ena, sizeof(e.ena), stdin);
    printf("Enter Employee no\n");
    scanf("%d", &e.eno);
    printf("Enter Employee salary\n");
    scanf("%f", &e.esal);
    printf("Employee name is %s\nNumber is %d\nsalary is %f", e.ena, e.eno, e.esal);

    return 0;
}
