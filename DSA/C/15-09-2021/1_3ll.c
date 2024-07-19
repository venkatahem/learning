// Evaluating postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int num;
    struct stack *next;
};

struct stack *head = NULL;

void push(int x);
int pop();

int main()
{
    int x;
    int y;
    int num;
    int i, j, k;
    char str[30];

    printf("Enter postfix expression(With space btw each term): ");
    fgets(str, 30, stdin);

    num = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            j = pop();
            k = pop();
            if (str[i] == '+')
            {
                y = j + k;
                push(y);
            }
            else if (str[i] == '-')
            {
                y = k - j;
                push(y);
            }
            else if (str[i] == '*')
            {
                y = j * k;
                push(y);
            }
            else if (str[i] == '/')
            {
                y = k / j;
                push(y);
            }
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            num = (num * 10) + (str[i] - '0');
        }
        else if (str[i] == ' ')
        {
            if (num != 0)
            {
                push(num);
                num = 0;
            }
            else
            {
                continue;
            }
        }
    }
    y = pop();
    printf("\n%s= %d\n", str, y);

    return 7;
}

void push(int x)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    if (head == NULL)
    {
        temp->num = x;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->num = x;
        temp->next = head;
        head = temp;
    }
}

int pop()
{
    int var;
    var = head->num;
    head = head->next;

    return var;
}