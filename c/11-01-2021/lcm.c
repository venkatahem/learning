#include <stdio.h>
int LCM(int a, int b);
 
int main()
{
    int x, y, lcm;
    printf("Enter 1st number for LCM : ");
    scanf("%d", &x);
    printf("Enter 2nd number for LCM : ");
    scanf("%d", &y);
    if(x >  y)
        lcm = LCM(y, x);
    else
        lcm= LCM(x, y);
    printf("The LCM of %d and %d :  %d\n\n", x, y, lcm);
    return 0;
}
int LCM(int a, int b)
{
    static int m = 0;
    m=m+b;
    if((m % a == 0) && (m % b == 0))
    {
        return m;
    }
    else
    {
        LCM(a, b);
    }
}