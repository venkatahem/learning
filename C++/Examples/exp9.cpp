#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int token = 1;
struct queue
{
    int patient_id;
    int priority;
    string disease;
    struct queue *next;
};

void enqueue(queue **front, queue **rear, string diseasename, int priority)
{
    struct queue *add = (struct queue *)malloc(sizeof(queue));
    add->patient_id = token;
    add->disease = diseasename;
    add->priority = priority;
    token++;
    if (*rear)
    {
        (*rear)->next = add;
        add->next = NULL;
        *rear = add;
    }
    else
    {
        add->next = NULL;
        *front = add;
        *rear = add;
    }
}

void dequeue(queue **front, queue **rear)
{
    if (*front)
    {
        struct queue *t = *front;
        *front = (*front)->next;
        free(t);
        if (*front == NULL)
        {
            *rear = NULL;
        }
    }
    else
    {
        cout << "No employees to serve";
    }
}

bool isEmpty(queue **front, queue **rear)
{
    if (*front == NULL && *rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print(queue **front)
{
    if (*front == NULL)
    {
        cout << "\nQueue is empty";
    }
    else
    {
        struct queue *t = *front;
        while (t)
        {
            cout << t->patient_id << " -> ";
            t = t->next;
        }
    }
}

int main()
{
    struct queue *front1 = NULL;
    struct queue *rear1 = NULL;
    struct queue *front2 = NULL;
    struct queue *rear2 = NULL;
    struct queue *front3 = NULL;
    struct queue *rear3 = NULL;
    string diseasename;
    int priority;
    cout << "CLINIC\n";
    while (1)
    {
        cout << "\n1.New Patient\n2.Call next patient\n3.Print a queue\n4.exit\n\n";
        cout << "Choose an option\n";
        int k;
        cin >> k;
        switch (k)
        {
        case 1:
            cout << "What it is disease name?\n";
            cin >> diseasename;
            cout << "\nWhat is the level of priority[High Priority(1)/Moderate Priority(2)/Low Priority(3)]\n";
            cin >> priority;
            if (priority == 1)
            {
                enqueue(&front1, &rear1, diseasename, priority);
            }
            else if (priority == 2)
            {
                enqueue(&front2, &rear2, diseasename, priority);
            }
            else if (priority == 3)
            {
                enqueue(&front3, &rear3, diseasename, priority);
            }
            break;
        case 2:
            if (isEmpty(&front1, &rear1) && isEmpty(&front2, &rear2))
            {
                dequeue(&front3, &rear3);
            }
            else if (isEmpty(&front1, &rear1))
            {
                dequeue(&front2, &rear2);
            }
            else
            {
                dequeue(&front1, &rear1);
            }
            break;
        case 3:
            cout << "Which queue do you wish to print(1/2/3)?\n";
            int n;
            cin >> n;
            if (n == 1)
                print(&front1);
            else if (n == 2)
                print(&front2);
            else if (n == 3)
                print(&front3);
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}