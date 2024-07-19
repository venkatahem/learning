#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct songs
{
    char song[20];
    struct songs *next;
};

struct playlist
{
    char song[20];
    struct playlist *next;
};

int count = 0;
int songc = 0;

struct playlist *list[1000];
struct playlist *pHead = NULL;
struct playlist *pEnd = NULL;

struct songs *sHead = NULL;
struct songs *sEnd = NULL;

void songsin();
void newplay();
void play();
void shuffle();
void display(int x);

int main()
{
    int x;
    int y;

    songsin();
    newplay();

    do
    {
        printf("\n1 --> Add more songs\n2 --> Create fresh playlist(After completing current one)\n3 --> Play songs\n4 --> Shuffle\n5 --> Songs list\n6 --> Display playlist\n0 --> Exit\n\nChoose: ");
        scanf("%d", &x);
        if (x == 1)
        {
            songsin();
        }
        else if (x == 2)
        {
            newplay();
        }
        else if (x == 3)
        {
            play();
        }
        else if (x == 4)
        {
            shuffle();
        }
        else if (x == 5)
        {
            display(1);
        }
        else if (x == 6)
        {
            display(2);
        }
    } while (x != 0);

    return 7;
}

void songsin()
{
    int x;
    int i;

    printf("Enter the no.of songs you want to add: ");
    scanf("%d", &x);
    getchar();
    for (i = 0; i < x; i++)
    {
        if (sHead == NULL)
        {
            struct songs *temp = (struct songs *)malloc(sizeof(struct songs));
            printf("\nEnter song name: ");
            fgets(temp->song, 20, stdin);
            temp->next = NULL;
            sHead = temp;
            sEnd = temp;
            songc++;
        }
        else
        {
            struct songs *temp = (struct songs *)malloc(sizeof(struct songs));
            printf("\nEnter song name: ");
            fgets(temp->song, 20, stdin);
            temp->next = NULL;
            sEnd->next = temp;
            sEnd = temp;
            songc++;
        }
    }
}

void newplay()
{
    int x;
    int i;
    struct songs *stemp = sHead;

    while (stemp != NULL)
    {
        struct playlist *temp = (struct playlist *)malloc(sizeof(struct playlist));
        strcpy(temp->song, stemp->song);
        temp->next = NULL;
        if (pHead == NULL)
        {
            pHead = temp;
            pEnd = temp;
            count++;
        }
        else
        {
            pEnd->next = temp;
            pEnd = temp;
            count++;
        }
        stemp = stemp->next;
    }
}

void play()
{
    int x;
    int i;
    struct playlist *temp = pHead;

    if (pHead == NULL)
    {
        printf("\nPlaylist Empty.............\n");
    }
    else
    {
        printf("\nTotal no.of songs: %d\n", count);
        printf("\nEnter the no.of songs to play: ");
        scanf("%d", &x);
        for (i = 0; (i < x) && (pHead != NULL); i++)
        {
            temp = pHead;
            printf("\nNow playing: %s", temp->song);
            if (pHead == pEnd)
            {
                pHead = NULL;
                pEnd = NULL;
                count = 0;
            }
            else
            {
                pHead = temp->next;
                free(temp);
                count--;
            }
        }
    }
}

void shuffle()
{
    int x;
    int i;
    struct playlist *temp = pHead;
    struct playlist *y;

    if (pHead == NULL)
    {
        printf("\nPlaylist Empty.............\n");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            list[i] = temp;
            temp = temp->next;
        }
        for (i = 0; i < count; i++)
        {
            x = rand() % count;
            y = list[i];
            list[i] = list[x];
            list[x] = y;
        }
        list[count - 1]->next = NULL;
        for (i = 0; i < count; i++)
        {
            if (i == 0)
            {
                pHead = list[0];
                temp = pHead;
            }
            else
            {
                temp->next = list[i];
                temp = temp->next;
            }
        }
        pEnd = list[count - 1];
    }
}

void display(int x)
{
    int y;
    int i = 1;

    if (x == 1)
    {
        printf("\nSongs.....\n");
        struct songs *stemp = sHead;
        while (stemp != NULL)
        {
            printf("\n%d) Song: %s", i++, stemp->song);
            stemp = stemp->next;
        }
        printf("\nTotal: %d", songc);
    }
    if (x == 2)
    {
        if (pHead == NULL)
        {
            printf("\nPlaylist Empty............\n");
        }
        else
        {
            printf("\nPlaylist\n");
            struct playlist *ptemp = pHead;
            while (ptemp != NULL)
            {
                printf("\n%d) Song: %s", i++, ptemp->song);
                ptemp = ptemp->next;
            }
            printf("\nTotal: %d", count);
        }
    }
}