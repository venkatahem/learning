//Infix to postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char ch;
    struct stack *next;
};

struct stack *head = NULL;

char postfix[30];
int post = -1;

void push(char *str, int i)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));

    if (head == NULL)
    {
        temp->ch = str[i];
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->ch = str[i];
        temp->next = head;
        head = temp;
    }
}

char pop()
{
    char var;
    var = head->ch;
    head = head->next;
    return var;
}

void pop_all()
{
    while (head != NULL)
    {
        post++;
        postfix[post] = head->ch;
        head = head->next;
    }
}

char check()
{
    if (head == NULL)
    {
        return 'x';
    }
    else
    {
        char var;
        var = head->ch;

        return var;
    }
}

int main()
{
    int x;
    int i;
    char infix[30];
    char a, b, c;

    printf("\nEnter infix expression: ");
    scanf("%s", infix);
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
        {
            push(infix, i);
        }
        else if (((infix[i] >= 'a') && (infix[i] <= 'z')) || ((infix[i] >= 'A') && (infix[i] <= 'Z')))
        {
            post++;
            postfix[post] = infix[i];
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            a = check();
            if (a == '+' || a == '-')
            {
                push(infix, i);
            }
            else if (a == '/' || a == '*')
            {
                b = pop();
                post++;
                postfix[post] = b;
                push(infix, i);
            }
            else
            {
                push(infix, i);
            }
        }
        else if (infix[i] == '+' || infix[i] == '-')
        {
            a = check();
            if (a == '/' || a == '*')
            {
                b = pop();
                post++;
                postfix[post] = b;
                a = check();
                if (a == '+' || a == '-')
                {
                    b = pop();
                    post++;
                    postfix[post] = b;
                    push(infix, i);
                }
                else
                {
                    push(infix, i);
                }
            }
            else if (a == '+' || a == '-')
            {
                b = pop();
                post++;
                postfix[post] = b;
                push(infix, i);
            }
            else
            {
                push(infix, i);
            }
        }
        else if (infix[i] == ')')
        {
            b = pop();
            post++;
            postfix[post] = b;
            c = pop();
        }
    }

    pop_all();

    printf("\n%s = %s\n\n", infix, postfix);

    return 7;
}