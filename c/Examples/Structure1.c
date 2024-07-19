#include <stdio.h>

struct emp
{
    int eno;
    char ena[20];
    float esal;
};

int main()
{
    struct emp e;
    printf("Enter Employee name\n");
    fgets(e.ena, sizeof(e.ena), stdin);
    printf("Enter Employee no\n");
    scanf("%d", &e.eno);
    printf("Enter Employee salary\n");
    scanf("%f", &e.esal);
    printf("Employee name is %s\nNumber is %d\nsalary is %f", e.ena, e.eno, e.esal);
    printf("\n%lu", sizeof(e));

    return 0;
}
