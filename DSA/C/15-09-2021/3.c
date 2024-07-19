#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int appno[SIZE];
int regno[1000];
int user[1000];
int count = -1;
int top = -1;
int rear = -1;

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (rear == (SIZE - 1))
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
    int x;
    int y;
    if (isFull())
    {
        printf("\nRegistration list is full.............\n");
    }
    else
    {
        if (top == -1)
        {
            top++;
            rear++;
            printf("\nEnter application number: ");
            scanf("%d", &appno[rear]);
        }
        else
        {
            rear++;
            printf("\nEnter application number: ");
            scanf("%d", &appno[rear]);
        }
    }
}

void pop()
{
    int x;
    int i;
    int arr[SIZE];
    if (isEmpty())
    {
        printf("\nApplication list is empty.....\n");
    }
    else
    {
        if (rear != 0)
        {
            count++;
            user[count] = appno[top];
            regno[count] = count + 1;
            printf("\nApplication Number: %d\nRegistration Number: %d", user[count], regno[count]);
            for (i = 0; i < (rear + 1); i++)
            {
                x = appno[i + 1];
                appno[i] = x;
            }
            rear--;
        }
        else
        {
            count++;
            user[count] = appno[top];
            regno[count] = count + 1;
            printf("\nApplication Number: %d\nRegistration Number: %d\n", user[count], regno[count]);
            appno[top] = 0;
            top = -1;
            rear = -1;
        }
    }
}

void display()
{
    int i;
    if (count == -1)
    {
        printf("\nNo registrations have been done\n");
    }
    else
    {
        for (i = 0; i < (count + 1); i++)
        {
            printf("\nApplication Number: %d\nRegistration Number: %d\n", user[i], regno[i]);
        }
    }
}
int main()
{
    int x;

    do
    {
        printf("\n1 --> Apply for registration\n2 --> Register a user\n3 -->Display Registered Users\nZero(0) --> Exit\n\nChoose: ");
        scanf("%d", &x);
        if (x == 1)
        {
            push();
        }
        else if (x == 2)
        {
            pop();
        }
        else if (x == 3)
        {
            display();
        }
    } while (x != 0);

    return 7;
}