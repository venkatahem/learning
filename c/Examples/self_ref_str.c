#include <stdio.h>
#include <stdlib.h>

struct exp
{
    int a;
    struct exp *next;
};
struct exp *root = NULL;
void input()
{
    int x;
        struct exp *temp = malloc(sizeof(struct exp));
        printf("\nEnter data: ");
        scanf("%d",&temp->a);
        temp->next = NULL;
        if(root == NULL)
        {
            root = temp;
        }
        else
        {
            struct exp *p;
            p = root;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
}
void output()
{
    struct exp *p;
    p = root;
    printf("\n");
    while(p->next != NULL)
    {
        printf("%d  ",p->a);
        p = p->next;
    }
    printf("%d  ",p->a);
    printf("\n");
}
void main()
{
    int x;
    do
    {
        printf("1==> INPUT\n2==> OUTPUT\n0==> EXIT");
        printf("\nEnter: ");
        scanf("%d",&x);
        getchar();
        switch (x)
        {
            case 1: input();
                    break;
            case 2: output();
                    break;
        }
    } while (x != 0);
    
}