#include <stdio.h>
void even_odd(int i, int n);
 
int main()
{
    int a,b;
    int c;
    printf("Input the range\n");
    printf("Starting number: ");
    scanf("%d", &a);
    printf("Ending number: ");
    scanf("%d",&b);
    c=a;
    printf("\nAll even numbers from 1 to %d are : ", a);
    if(a%2==0)
    even_odd(a, b); 
    else
    even_odd(c+1,b);
    printf("\nAll odd numbers from 1 to %d are : ", a);
    if(a%2==0)
    even_odd(c+1, b);
    else
    even_odd(a,b);

    return 0;
}
void even_odd(int i, int n)
{
    if(i > n)
    {
        return;
    }
    printf("%d  ", i);
    even_odd(i+2, n);
}