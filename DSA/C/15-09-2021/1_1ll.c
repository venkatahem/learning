// Prefix To Infix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char ch[30];
    struct stack *next;
};

struct stack *head = NULL;

char var[30];

void push(char *str)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));

    if (head == NULL)
    {
        strcpy(temp->ch, str);
        temp->next = NULL;
        head = temp;
    }
    else
    {
        strcpy(temp->ch, str);
        temp->next = head;
        head = temp;
    }
}

char *pop()
{
    strcpy(var, head->ch);
    head = head->next;

    return var;
}

int main()
{
    int i;
    char prefix[50], op1[30], op2[30], op[3], ex[4], opr[50], lb[2] = "(", rb[2] = ")";
    printf("\nEnter a prefix expression: ");
    scanf("%s", prefix);

    for (i = (strlen(prefix) - 1); i >= 0; i--)
    {
        if (((prefix[i] >= 'a') && (prefix[i] <= 'z')) || ((prefix[i] >= 'A') && (prefix[i] <= 'Z')))
        {
            op[0] = prefix[i];
            strcpy(opr, op);
            push(opr);
        }
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '/' || prefix[i] == '*')
        {
            ex[0] = prefix[i];
            strcpy(op1, pop());
            strcpy(op2, pop());

            strcpy(opr, lb);
            strcat(opr, op1);
            strcat(opr, ex);
            strcat(opr, op2);
            strcat(opr, rb);

            push(opr);
        }
    }

    printf("\n%s = %s\n\n", prefix, head->ch);

    return 7;
}