#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void prims(vector<vector<int>> graph, int size)
{
    // key-->dist
    int key[size], parent[size], i, ver, min_index, min;
    bool mst[size];

    for (i = 0; i < size; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[0] = 0;

    for (i = 0; i < size - 1; i++)
    {
        min = INT_MAX;
        for (int j = 0; j < size; j++)
        {
            if (mst[j] == false && key[j] < min)
            {
                min = key[j];
                min_index = j;
                // cout << "min: " << min;
            }
        }
        ver = min_index;
        mst[ver] = true;

        for (int k = 0; k < size; k++)
        {
            int temp = graph[ver][k];

            if ((temp != 0) && (mst[k] == false) && (temp < key[k]))
            {
                parent[k] = ver;
                key[k] = temp;
            }
        }
    }
    cout << "\nSolution\n";
    for (i = 1; i < size; i++)
    {
        cout << "Edge: " << parent[i] << " --- " << i << "\tWeight: " << key[i] << "\n";
    }
}

int main()
{
    int n, e, i, j, u, v;
    cout << "Vertices: ";
    cin >> n;
    cout << "No.of edges: ";
    cin >> e;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Input the vertices(with space between them) & edge weights\n";

    for (i = 0; i < e; i++)
    {
        cout << "Vertices: ";
        cin >> u >> v;
        cout << "Weight: ";
        cin >> j;

        graph[u][v] = j;
        graph[v][u] = j;
    }
    cout << "\nEntered graph:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    prims(graph, n);
    return 0;
}