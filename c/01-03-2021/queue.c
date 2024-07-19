#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int a;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;
void insert()
{
    struct queue *node = malloc(sizeof(struct queue));
    printf("\nEnter data: ");
    scanf("%d",&node->a);
    node->next = NULL;
    if(front == NULL)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear->next = node;
        rear = node;
    }
}
void display()
{
    struct queue *temp;
    temp = front;
    printf("\n");
    while(temp != NULL)
    {
        printf("%d\n",temp->a);
        temp = temp->next;
    }
    printf("\n");
}
void delete()
{
    struct queue *temp;
    if(front == NULL)
    {
        printf("\nNo elements to delete\n");
    }
    else
    {
        temp = front;
        printf("\nDeleted element: %d",temp->a);
        front = front->next;
        free(temp);
    }
}
int main()
{
    int x;
    do
    {
        printf("\n1 ==> INSERT\n2 ==> DISPLAY\n3 ==> DELETE\n0 ==> EXIT\nEnter: ");
        scanf("%d",&x);
        switch (x)
        {
            case 1: insert();
                    break;
            case 2: display();
                    break;
            case 3: delete();
                    break;
        }
    } while (x != 0);
    
}