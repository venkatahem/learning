// BFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs_trav;
void list(vector<int> temp[], int a, int b)
{
    temp[a].push_back(b);
    temp[b].push_back(a);
}

void print_list(vector<int> temp[], int n)
{
    cout << "HI";
    int i, j;

    cout << "\nAdjacency list of the graph";

    for (i = 0; i < n; i++)
    {
        cout << "\n"
             << i;
        for (j = 0; j < temp[i].size(); j++)
        {
            cout << " -> " << temp[i][j];
        }
    }
    cout << "\n";
}

void bfs(int ver, vector<int> graph[], vector<int> tree[], int visited[])
{
    int i;
    int node = ver;
    // cout << "\nNode " << node;
    visited[ver] = 1;
    bfs_trav.push_back(node);
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        for (i = 0; i < graph[node].size(); i++)
        {
            if (visited[graph[node][i]] == 0)
            {
                visited[graph[node][i]] = 1;
                tree[node].push_back(graph[node][i]);
                bfs_trav.push_back(graph[node][i]);
                q.push(graph[node][i]);
            }
        }
        q.pop();
        node = q.front();
    }
}

void pre_trav(int ver, vector<int> tree[])
{
    for (int i = 0; i < tree[ver].size(); i++)
    {
        cout << tree[ver][i] << " ";
        pre_trav(tree[ver][i], tree);
    }
}

int main()
{
    int n, e, i, a, b;
    cout << "No.of nodes: ";
    cin >> n;
    vector<int> adj_list[n];
    vector<int> span_tree[n];
    cout << "No.of edges: ";
    cin >> e;

    int visited[n] = {0};
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        span_tree[i] = {};
    }
    for (i = 0; i < e; i++)
    {
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        // list(adj_list, a, b);
    }
    print_list(adj_list, n);
    cout << "\nVertex: ";
    cin >> e;
    bfs(e, adj_list, span_tree, visited);
    cout << "BFS traversal: ";
    for (i = 0; i < bfs_trav.size(); i++)
    {
        cout << bfs_trav[i] << "  ";
    }
    cout << "\nPre-order traversal of spanning tree:\n"
         << e << " ";
    pre_trav(e, span_tree);
    return 0;
}