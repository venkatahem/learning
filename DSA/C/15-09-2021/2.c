#include <stdio.h>
#include <stdlib.h>

int songs[1000];
int shuffle[1000];
int played[1000];
int end = 0;
int len;

void songsin()
{
    int i;
    printf("\nEnter the No.of songs: ");
    scanf("%d", &len);
    for (i = 0; i < len; i++)
    {
        printf("\nSong - %d : ", i + 1);
        scanf("%d", &songs[i]);
    }
    end = len;
}

void fresh_list()
{
    int i;
    for (i = 0; i < len; i++)
    {
        shuffle[i] = songs[i];
    }
    end = len;
}

void song_shuffle()
{
    int i;
    int temp;
    int ran_index;
    for (i = 0; i < end; i++)
    {
        ran_index = rand() % end;
        temp = shuffle[i];
        shuffle[i] = shuffle[ran_index];
        shuffle[ran_index] = temp;
    }
}

void play()
{
    int x;
    int y;
    int i;
    printf("\nNo.of songs to play: ");
    scanf("%d", &x);
    printf("\n");
    for (i = 0; i < x; i++)
    {
        printf("Playing now: %d\n", shuffle[i]);
    }
    for (i = 0; i < x; i++)
    {
        for (y = 0; y < end; y++)
        {
            shuffle[y] = shuffle[y + 1];
        }
        end--;
    }
}

void display()
{
    int i;
    printf("\nYour playlist:\n");
    for (i = 0; i < end; i++)
    {
        printf("%d\t", shuffle[i]);
    }
    printf("\n");
}

int main()
{
    int x;

    songsin();
    fresh_list();
    do
    {
        printf("\n1 --> Create a fresh playlist\n2 --> Shuffle the playlist\n3 --> Play a song\n4 --> See your playlist\nZero(0) --> Exit\n\nChoose: ");
        scanf("%d", &x);
        if (x == 1)
        {
            fresh_list();
        }
        else if (x == 2)
        {
            song_shuffle();
        }
        else if (x == 3)
        {
            play();
        }
        else if (x == 4)
        {
            display();
        }
    } while (x != 0);

    return 7;
}