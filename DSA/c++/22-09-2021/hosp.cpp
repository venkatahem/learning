#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

struct queue
{
    int id;
    int priority;
    string disease;
    string name;
    struct queue *next;
};

struct queue *head1 = NULL;
struct queue *head2 = NULL;
struct queue *head3 = NULL;
struct queue *end1 = NULL;
struct queue *end2 = NULL;
struct queue *end3 = NULL;
struct queue *vHead = NULL;
struct queue *vEnd = NULL;
int count = 0;
int uid = 0;

void entry(queue **head, queue **end, string n, string dis, int p)
{
    // struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    struct queue *temp = new queue();
    uid++;
    temp->disease = dis;
    temp->id = uid;
    temp->name = n;
    temp->priority = p;
    if (*head == NULL)
    {
        temp->next = NULL;
        *head = temp;
        *end = temp;
    }
    else
    {

        temp->next = NULL;
        (*end)->next = temp;
        *end = temp;
    }
    count++;
}

void plist()
{
    struct queue *temp;
    if (head1 != NULL)
    {
        temp = head1;
        while (temp != NULL)
        {
            cout << "\nID: " << temp->id << "\nDisease: " << temp->disease << "\nPriority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
    else
    {
        cout << "\n.....No patients in priority 1.....\n";
    }
    if (head2 != NULL)
    {
        temp = head2;
        while (temp != NULL)
        {
            cout << "\nID: " << temp->id << "\nDisease: " << temp->disease << "\nPriority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
    else
    {
        cout << "\n.....No patients in priority 2.....\n";
    }
    if (head3 != NULL)
    {
        temp = head3;
        while (temp != NULL)
        {
            cout << "\nID: " << temp->id << "\nDisease: " << temp->disease << "\nPriority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
    else
    {
        cout << "\n.....No patients in priority 3.....\n";
    }
    cout << "\nTotal patient count: " << count << endl;
}

void call()
{
    struct queue *temp = NULL;
    // struct queue *ltemp = (struct queue *)malloc(sizeof(struct queue));
    struct queue *ltemp = new queue();
    if (head1 != NULL)
    {
        cout << "\nId: " << head1->id << "\nName: " << head1->name << "\nDisease: " << head1->disease << "\nPriority: " << head1->priority << endl;
        temp = head1;
        if (head1 == end1)
        {
            head1 = NULL;
            end1 = NULL;
        }
        else
        {
            head1 = head1->next;
        }
        count--;
    }
    else if (head2 != NULL)
    {
        cout << "\nNo patients in priority 1\n";
        cout << "\nId: " << head2->id << "\nName: " << head2->name << "\nDisease: " << head2->disease << "\nPriority: " << head2->priority << endl;
        temp = head2;
        if (head2 == end2)
        {
            head2 = NULL;
            end2 = NULL;
        }
        else
        {
            head2 = head2->next;
        }
        count--;
    }
    else if (head3 != NULL)
    {
        cout << "\nNo patients in priority 1 and 2\n";
        cout << "\nId: " << head3->id << "\nName: " << head3->name << "\nDisease: " << head3->disease << "\nPriority: " << head3->priority << endl;
        temp = head3;
        if (head3 == end3)
        {
            head3 = NULL;
            end3 = NULL;
        }
        else
        {
            head3 = head3->next;
        }
        count--;
    }
    else
    {
        cout << "\nNo patients in the waiting list\n";
    }

    if (temp != NULL)
    {
        ltemp->disease = temp->disease;
        ltemp->name = temp->name;
        ltemp->id = temp->id;
        ltemp->priority = temp->priority;
        ltemp->next = NULL;

        if (vHead == NULL)
        {
            vHead = ltemp;
            vEnd = ltemp;
        }
        else
        {
            vEnd->next = ltemp;
            vEnd = ltemp;
        }
        free(temp);
    }
}

void called()
{
    struct queue *temp;
    if (vHead == NULL)
    {
        cout << "\nNo patient has been checked (or) no entry have been taken\n";
    }
    else
    {
        temp = vHead;
        while (temp != NULL)
        {
            cout << "\nID: " << temp->id << "\nName:" << temp->name << "\nDisease: " << temp->disease << "\nPriority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    int x;
    int y;
    string disease;
    string name;
    do
    {
        cout << "\n1 --> New patient entry\n2 --> Call next patient\n3 --> Patients list\n4 --> Completed checkups\n0 --> Exit\n\nChoose: ";
        cin >> x;
        getchar();
        if (x == 1)
        {
            cout << "\nEnter patient name: ";
            getline(cin, name);
            cout << "\nDisese patient suffering from: ";
            getline(cin, disease);
            cout << "\nDisease severity(1 -> High, 2 -> Medium, 3 -> Low): ";
            cin >> y;
            if (y == 1)
            {
                entry(&head1, &end1, name, disease, y);
            }
            else if (y == 2)
            {
                entry(&head2, &end2, name, disease, y);
            }
            else if (y == 3)
            {
                entry(&head3, &end3, name, disease, y);
            }
        }
        else if (x == 2)
        {
            call();
        }
        else if (x == 3)
        {
            plist();
        }
        else if (x == 4)
        {
            called();
        }
    } while (x != 0);

    return 7;
}
