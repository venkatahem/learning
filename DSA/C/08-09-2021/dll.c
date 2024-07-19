#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *root = NULL;

int isEmpty();

void display();

void insert();

void delete ();

int length();

int main()
{
    int x;
    int y;
    printf("\n---------- D O U B L Y  L I N K E D  L I S T ----------\n");
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
            delete ();
        }
        else if (x == 3)
        {
            display();
        }
        else if (x == 4)
        {
            y = length();
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
        printf("\n");
        struct node *p;
        p = root;
        while (p->next != NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
        printf("%d\n", p->data);
    }
}

void insert()
{
    int x;
    int y;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = root;
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    if (root == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        root = temp;
    }
    else
    {
        printf("\n1 --> END\n2 --> AT HEAD\n3 --> After a value\n4 --> Before a value\nChoose: ");
        scanf("%d", &y);
        if (y == 1)
        {
            //end
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
            temp->prev = p;
            temp->next = NULL;
        }
        else if (y == 2)
        {
            //start
            p->prev = temp;
            temp->next = root;
            temp->prev = NULL;
            root = temp;
        }
        else if (y == 3)
        {
            //After
            printf("\nEnter the data after which this is to be added: ");
            scanf("%d", &x);
            while (p->data != x)
            {
                p = p->next;
            }
            temp->prev = p;
            temp->next = p->next;
            p->next = temp;
        }
        else if (y == 4)
        {
            // B E F O R E
            printf("\nEnter the data before which this is to be added: ");
            scanf("%d", &x);
            while (p->data != x)
            {
                p = p->next;
            }
            temp->prev = p->prev;
            temp->next = p;
            p->prev->next = temp;
            p->prev = temp;
        }
    }
}

void delete ()
{
    int x;
    int y;
    struct node *p;
    p = root;

    if (isEmpty())
    {
        printf("\nNo Data......");
    }
    else
    {

        printf("1 --> Delete a given value\n2 --> Head data\n3 --> AT End\n4 --> After a value\n5 --> Before a value\nChoose: ");
        scanf("%d", &y);
        //y = 1;
        if (y == 1)
        {
            // V A L U E
            printf("Enter the data value to delete: ");
            scanf("%d", &x);
            if (root->data == x)
            {
                p = p->next;
                free(root);
                p->prev = NULL;
                root = p;
            }
            else
            {

                while (p->data != x)
                {

                    p = p->next;
                }
                if (p->next == NULL)
                {
                    p->prev->next = NULL;
                    free(p);
                }
                else
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    free(p);
                }
            }
        }
        else if (y == 2)
        {
            // H E A D
            p = p->next;
            free(root);
            p->prev = NULL;
            root = p;
        }
        else if (y == 3)
        {
            // E N D
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->prev->next = NULL;
            free(p);
        }
        else if (y == 4)
        {
            // A F T E R
            printf("Enter the data value: ");
            scanf("%d", &x);
            struct node *temp;
            while (p->data != x)
            {
                p = p->next;
            }
            temp = p->next;
            p->next = temp->next;
            temp->next->prev = p;
            free(temp);
        }
        else if (y == 5)
        {
            // B E F O R E
            printf("Enter the data value: ");
            scanf("%d", &x);
            struct node *pres;
            struct node *temp;
            while (p->data != x)
            {
                pres = p;
                p = p->next->next;
            }
            temp = pres->next;
            pres->next = p;
            p->prev = pres;
            free(temp);
        }
    }
}

int length()
{
    int x;
    struct node *p;
    p = root;
    x = 0;
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        while (p->next != NULL)
        {
            x++;
            p = p->next;
        }
        x++;
        return x;
    }
}