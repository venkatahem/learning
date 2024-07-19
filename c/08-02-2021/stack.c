#include <stdio.h> 
#include <stdlib.h> 
struct stack
{
    int x;
    struct stack *s;
};
struct stack *s1 = NULL;
void pop();
void push(int a);
void show();
void search(struct stack s);
int main()
{
    int n,c;
    printf("\nProgram to perform stack\n");
    do
    {
        printf("\n1 for push\n2 for pop\n3 to show stack\n0 to exit\n");
        printf("Enter choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                   printf("Enter the element: ");
                   scanf("%d",&c);
                   push(c);
                   break;
            case 2:printf("Poping out an element");
                   pop();
                   break;
            case 3:printf("Displaying the elemets");
                   show();
                   break;
        }
    } while (n!=0);
        
}
void push(int a)
{
    struct stack *s2 = malloc(sizeof(struct stack));
    s2->x = a;
    s2->s = s1;
    s1 = s2;
}
void show()
{
    struct stack *temp;
    temp = s1;
    while(temp != NULL)
    {
        printf("\n%d",temp->x);
        temp = temp->s;
    }
}
void pop()
{
    if(s1 == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        struct stack *temp;
        temp = s1;
        s1 = s1->s;
        printf("\n%d deleted",temp->x);
        free(temp);
    }
}