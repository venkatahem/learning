#include <iostream>
using namespace std;
int songs[1000], c = 0;
void create();
void play();
void shuffle();
int ran();
int main()
{
    int x;
    int n = 0;
    do
    {
        if (n == 0)
        {
            cout << "1->Create a Playlist\n2->Shuffle the playlist\n3->Play songs\n4->Exit\n";
            cin >> x;
        }
        else
        {
            cout << "\n2->Shuffle the playlist\n3->Play songs\n4->Exit\n";
            cin >> x;
        }
        if (x == 1)
        {

            create();
            n++;
        }
        else if (x == 2)
        {
            shuffle();
        }
        else if (x == 3)
        {
            int arrSize = sizeof(songs) / sizeof(songs[0]);
            play();
        }
    } while (x != 4);
    return 0;
}
void create()
{
    int n;
    cout << "\nEnter the number of songs:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter song" << i + 1 << " name:";
        cin >> songs[i];
        c++;
    }
}
void play()
{
    if (c == 0)
    {
        cout << "\nNo songs in the playlist :(\n";
    }
    else
    {
        for (int i = 0; i < c; i++)
        {
            cout << songs[i] << " ";
        }
    }
}
int ran()
{
    srand((unsigned)ftime(NULL));
    int random = rand() % 10;
    while (!((random >= c / 2) && (random < c)))
    {
        random = rand() % 10;
    }
    //cout<<random;
    return random;
}
void shuffle()
{
    int temp;
    for (int i = 0; i <= c / 2; i++)
    {
        int r = ran();
        temp = songs[r];
        songs[r] = songs[i];
        songs[i] = temp;
    }
}