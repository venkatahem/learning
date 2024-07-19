#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct application
{
    char name[30];
    int appli;
    struct application *next;
};

struct registration
{
    char name[30];
    int appli;
    int regno;
    struct registration *next;
};

int reg = 0;

struct application *aRoot = NULL;
struct application *aEnd = NULL;
struct registration *rRoot = NULL;
struct registration *rEnd = NULL;

int length(int x);
void display(int x);
void regist();
void apply();

int main()
{
    int x;
    int y;

    do
    {
        printf("\n\n1 --> Apply for registration\n2 --> Register a user\n3 --> Display pending applications\n4 -->Display Registered Users\nZero(0) --> Exit\n\nChoose: ");
        scanf("%d", &x);
        if (x == 1)
        {
            apply();
        }
        else if (x == 2)
        {
            regist();
        }
        else if (x == 3)
        {
            display(1);
        }
        else if (x == 4)
        {
            display(2);
        }
    } while (x != 0);

    return 7;
}

void apply()
{
    int x;

    struct application *temp;
    temp = (struct application *)malloc(sizeof(struct application));
    printf("Enter application no: ");
    scanf("%d", &temp->appli);
    getchar();
    printf("\nEnter name: ");
    fgets(temp->name, 30, stdin);
    temp->next = NULL;

    if (aRoot == NULL)
    {
        aRoot = temp;
        aEnd = temp;
    }
    else
    {
        aEnd->next = temp;
        aEnd = temp;
    }
}

void regist()
{
    int x;
    int i;
    int len;
    struct application *temp;
    struct registration *rtemp;
    len = length(1);
    temp = aRoot;
    if (aRoot == NULL)
    {
        printf("\nNo pending applications (OR) No entries");
    }
    else
    {
        printf("\nNo.of pending registration(s): %d\n", len);
        printf("\n1 --> Register selected no.of users\n2 --> Register all\n\nChoose: ");
        scanf("%d", &x);
        if (x == 1)
        {
            printf("\nNo.of users: ");
            scanf("%d", &len);
            for (i = 0; (i < len) && (aRoot != NULL); i++)
            {
                rtemp = (struct registration *)malloc(sizeof(struct registration));
                if (rRoot == NULL)
                {
                    strcpy(rtemp->name, temp->name);
                    rtemp->appli = temp->appli;
                    reg++;
                    rtemp->regno = reg;
                    printf("\nRegistered....\nName: %sApp.No: %d\nReg.No: %d\n", rtemp->name, rtemp->appli, rtemp->regno);
                    rRoot = rtemp;
                    rEnd = rtemp;
                    rEnd->next = NULL;
                    aRoot = temp->next;
                    free(temp);
                }
                else
                {
                    temp = aRoot;
                    strcpy(rtemp->name, temp->name);
                    rtemp->appli = temp->appli;
                    reg++;
                    rtemp->regno = reg;
                    printf("\nRegistered....\n\nName: %sApp.No: %d\nReg.No: %d\n", rtemp->name, rtemp->appli, rtemp->regno);
                    if (aRoot == aEnd)
                    {
                        rEnd->next = rtemp;
                        rEnd = rtemp;
                        aRoot = NULL;
                        aEnd = NULL;
                    }
                    else
                    {
                        rEnd->next = rtemp;
                        rEnd = rtemp;
                        aRoot = temp->next;
                        free(temp);
                    }
                    rEnd->next = NULL;
                }
            }
        }
        else if (x == 2)
        {
            while (aRoot != NULL)
            {
                rtemp = (struct registration *)malloc(sizeof(struct registration));
                if (rRoot == NULL)
                {
                    strcpy(rtemp->name, temp->name);
                    rtemp->appli = temp->appli;
                    reg++;
                    rtemp->regno = reg;
                    printf("\nRegistered....\nName: %sApp.No: %d\nReg.No: %d\n", rtemp->name, rtemp->appli, rtemp->regno);
                    rRoot = rtemp;
                    rEnd = rtemp;
                    rEnd->next = NULL;
                    aRoot = temp->next;
                    free(temp);
                }
                else
                {

                    temp = aRoot;
                    strcpy(rtemp->name, temp->name);
                    rtemp->appli = temp->appli;
                    reg++;
                    rtemp->regno = reg;
                    printf("\nRegistered....\n\nName: %sApp.No: %d\nReg.No: %d\n", rtemp->name, rtemp->appli, rtemp->regno);
                    if (aRoot == aEnd)
                    {
                        rEnd->next = rtemp;
                        rEnd = rtemp;
                        aRoot = NULL;
                        aEnd = NULL;
                    }
                    else
                    {
                        rEnd->next = rtemp;
                        rEnd = rtemp;
                        aRoot = temp->next;
                        free(temp);
                    }
                    rEnd->next = NULL;
                }
            }
        }
    }
}

void display(int x)
{
    int y;
    struct application *temp;
    struct registration *rtemp;
    if (x == 1)
    {
        if (aRoot == NULL)
        {
            printf("\nNo pending applications (OR) No entries");
        }
        else
        {
            temp = aRoot;
            printf("\nPending applications...\n");
            while (temp != NULL)
            {
                printf("\nName: %sApp.No: %d\n", temp->name, temp->appli);
                temp = temp->next;
            }

            y = length(1);

            printf("\nTotal: %d", y);
        }
    }
    else if (x == 2)
    {
        if (rRoot == NULL)
        {
            printf("\nNo registered users");
        }
        else
        {
            printf("\nRegistered....\n");
            rtemp = rRoot;
            while (rtemp != NULL)
            {
                printf("\nName: %sApp.No: %d\nReg.No: %d\n", rtemp->name, rtemp->appli, rtemp->regno);
                rtemp = rtemp->next;
            }

            y = length(2);
            printf("\nTotal: %d", y);
        }
    }
}

int length(int x)
{
    int l = 0;
    struct application *ap;
    struct registration *rp;
    if (x == 1)
    {
        if (aRoot == NULL)
        {

            return 0;
        }
        else
        {
            ap = aRoot;
            while (ap != NULL)
            {
                l++;
                ap = ap->next;
            }
            return l;
        }
    }
    else if (x == 2)
    {
        if (rRoot == NULL)
        {
            return 0;
        }
        else
        {

            rp = rRoot;
            while (rp != NULL)
            {
                l++;
                rp = rp->next;
            }
            return l;
        }
    }
}