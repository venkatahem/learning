#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

int isfull()
{
    if((SIZE-top) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push()
{
    int a;
    if(isfull())
    {
        printf("\nStack capacity is full\n");
    }
    else
    {
        printf("\nEnter the element to insert: ");
        scanf("%d",&a);
        top++;
        stack[top] = a;
    }
}

void pop()
{
    if(isempty())
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nElement: %d is popped out\n",stack[top]);
        top--;
    }
}



void display()
{
    int i;
    printf("\n");
    for(i = 0;i <= top;i++)
    {
        printf(" %d \n",stack[i]);
    }
}

void size(){printf("\nSize of stack is %d\n",top+1);}

void main()
{
    int x;
    do
    {
        printf("\n1 ==> PUSH\n2 ==> POP\n3 ==> DISPLAY\n4 ==> SIZE\n..........\n0 ==> EXIT\n\nEnter: ");
        scanf("%d",&x);
        switch(x)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: size();
                    break;
        }
    } while (x != 0);
    
}