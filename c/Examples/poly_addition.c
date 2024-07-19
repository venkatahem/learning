#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    struct poly *next;
};

struct poly *eq1 = NULL;
struct poly *eq2 = NULL;
struct poly *eq3 = NULL;

void input(struct poly **root, int eq, int deg)
{
    int temp;
    int i;
    struct poly *curr;
    printf("Input for equation %d\n", eq);
    for (i = deg; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("\nEnter the co-efficient of X^%d(or constant(C)): ", i);
            scanf("%d", &temp);
            struct poly *new = (struct poly *)malloc(sizeof(struct poly));
            new->coeff = temp;
            new->next = NULL;
            if (*root == NULL)
            {
                *root = new;
            }
            else
            {
                curr = *root;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = new;
            }
        }
        else if (i != 0)
        {
            printf("\nEnter the co-efficient of X^%d: ", i);
            scanf("%d", &temp);
            struct poly *new = (struct poly *)malloc(sizeof(struct poly));
            new->coeff = temp;
            new->next = NULL;
            if (*root == NULL)
            {
                *root = new;
            }
            else
            {
                curr = *root;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = new;
            }
        }
    }
}

void add_poly(struct poly **root, int deg)
{
    int temp, x, y;
    int i, j;
    struct poly *curr, *temp1, *temp2;
    temp1 = eq1;
    temp2 = eq2;
    for (i = 0; i <= deg; i++)
    {
        x = temp1->coeff;
        y = temp2->coeff;
        temp = x + y;
        temp1 = temp1->next;
        temp2 = temp2->next;
        struct poly *new = (struct poly *)malloc(sizeof(struct poly));
        new->coeff = temp;
        new->next = NULL;
        if (*root == NULL)
        {
            *root = new;
        }
        else
        {
            curr = *root;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = new;
        }
    }
}

void display(struct poly **root, int eq, int deg)
{
    struct poly *temp;
    int temp1, i;
    printf("\nEquation: %d\n", eq);
    i = deg;
    temp = *root;
    while (temp->next != NULL)
    {
        printf("(%d)X^%d + ", temp->coeff, i);
        temp = temp->next;
        i--;
    }
    printf("(%d)X^%d = 0", temp->coeff, i);
}

int main()
{
    int deg, i;
    struct poly *temp3, *temp1, *temp2;
    printf("Enter the degree of polynomial equation: ");
    scanf("%d", &deg);
    input(&eq1, 1, deg);
    input(&eq2, 2, deg);

    add_poly(&eq3, deg);

    display(&eq1, 1, deg);
    display(&eq2, 2, deg);
    display(&eq3, 3, deg);

    return 7;
}