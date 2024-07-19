#include <stdio.h>
#include <stdlib.h>

struct library
{
    char name[30];
    char author[20];
    int id;
    int cost;
    int d,m,y;
    struct library *next;
};
struct library *root = NULL;
void input()
{
    static int i =1;
    int x;
    struct library *node = malloc(sizeof(struct library));
    
        printf("\nBook %d\n",i);
        printf("Enter the name of the book\n");
        scanf("%s",node->name);
        printf("Enter author name\n");
        scanf("%s",node->author);
        printf("Enter the cost: ");
        scanf("%d",&node->cost);
        printf("Enter the date of purchase in DD-MM-YYYY format\n");
        scanf("%d",&x);
        node->d = x;
        scanf("%d",&x);
        node->m = x;
        scanf("%d",&x);
        getchar();
        node->y = x;
        node->id = i;
        node->next = NULL;
        if(root == NULL)
        {
            root = node;
        }
        else
        {
            struct library *temp;
            temp = root;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        i++;
}
void search()
{
    int x,y=0;
    printf("\nEnter book ID: ");
    scanf("%d",&x);
    struct library *temp = root;
    while(temp->next != NULL)
    {
        if(temp->id == x)
        {
            y = 1;
            printf("\nBook name: %s",temp->name);
            printf("\nAuthor: %s",temp->author);
            printf("\nCost: %d\n",temp->cost);
            break;
        }

        temp = temp->next;
    }
    if(y == 0)
    {
        printf("\n\nBook not found\n\n");
    }
}
void main()
{
    int x;
    do
    {
        printf("\n1==> INPUT\n2==> SEARCH\n0==> EXIT");
        printf("\nEnter: ");
        scanf("%d",&x);
        getchar();
        switch (x)
        {
            case 1: input();
                    break;
            case 2: search();
                    break;
        }
    } while (x != 0);
}