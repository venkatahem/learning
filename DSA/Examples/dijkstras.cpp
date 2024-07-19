#include <iostream>

using namespace std;

#define ver 9
#define MAX 99999999
// int ver = 5;

void dijkstras(int graph[ver][ver])
{
    int dist[ver];
    bool shrt[ver];
    int i, j;
    int source, u;
    cout << "Enter source vertex: ";
    cin >> source;
    for (i = 0; i < ver; i++)
    {
        shrt[i] = false;
        dist[i] = MAX;
    }
    dist[source] = 0;

    for (i = 0; i < ver; i++)
    {

        int min = MAX;

        for (j = 0; j < ver; j++)
        {
            if (shrt[j] == false && dist[j] <= min)
            {
                min = dist[j];
                u = j;
            }
        }

        shrt[u] = true;

        for (j = 0; j < ver; j++)
        {
            if (shrt[j] == false && graph[u][j] != 0 && (dist[j] > dist[u] + graph[u][j]))
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    cout << "\nSource vertex: " << source << endl;
    cout << "Distance from source vertex: " << endl;
    for (int x = 0; x < ver; x++)
    {
        cout << "Dist - " << x << " :" << dist[x] << endl;
    }
}

int main()
{
    int graph[ver][ver] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                           {0, 0, 4, 14, 10, 0, 2, 0, 0},
                           {0, 0, 0, 0, 0, 2, 0, 1, 6},
                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                           {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    cout << "Graph:\n\n";
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            if (j == 0)
            {
                cout << graph[i][j] << "  ";
            }
            else
                printf("%5d", graph[i][j]);
        }

        cout << "\n";
    }

    dijkstras(graph);
}