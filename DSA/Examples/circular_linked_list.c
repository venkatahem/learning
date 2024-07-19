#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *root = NULL;

int isEmpty();

void display();

void insert();

//void delete ();

//int length();

int main()
{
    int x;
    int y;
    do
    {
        printf("\n1 --> Insert(Append)\n2 --> Delete\n3 --> Display\n4 --> Length\n5 --> Exit\nChoose: ");
        scanf("%d", &x);
        if (x == 1)
        {
            insert();
        }
        else if (x == 2)
        {
            //   delete ();
        }
        else if (x == 3)
        {
            display();
        }
        else if (x == 4)
        {
            // y = length();
            printf("Length of list: %d", y);
        }
    } while (x != 5);

    return 7;
}

int isEmpty()
{
    if (root == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nNo Data.......");
    }
    else
    {
        struct node *p;
        p = root;
        while (p->next != root)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("%d", p->data);
    }
}

void insert()
{
    int x;
    int y;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    if (root == NULL)
    {
        root = temp;
        temp->next = root;
    }
    else
    {
        printf("\n1 --> END\n2 --> AT HEAD\n3 --> After a value\n4 --> Before a value\nChoose: ");
        scanf("%d", &y);
        if (y == 1)
        {
            // E N D
            struct node *p;
            p = root;

            while (p->next != root)
            {
                p = p->next;
            }
            p->next = temp;
            temp->next = root;
        }
        else if (y == 2)
        {
            // S T A R T
            struct node *p;
            p = root;
            while (p->next != root)
            {
                p = p->next;
            }
            p->next = temp;
            temp->next = root;
            root = temp;
        }
        else if (y == 3)
        {
            // A F T E R
            printf("\nEnter the data after which this is to be added: ");
            scanf("%d", &x);
            struct node *p;
            p = root;
            while (p->data != x)
            {
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
        }
        else if (y == 4)
        {
            // B E F O R E
            printf("\nEnter the data before which this is to be added: ");
            scanf("%d", &x);
            struct node *p;
            struct node *prev;
            p = root;
            while (p->data != x)
            {
                prev = p;
                p = p->next;
            }
            temp->next = prev->next;
            prev->next = temp;
        }
    }
}