// DFS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dfs_trav;
void list(vector<int> temp[], int a, int b)
{
    temp[a].push_back(b);
    temp[b].push_back(a);
}

void print_list(vector<int> temp[], int n)
{
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
}

void dfs(int ver, vector<int> graph[], int visited[])
{
    dfs_trav.push_back(ver);
    visited[ver] = 1;
    for (int i = 0; i < graph[ver].size(); i++)
    {
        if (visited[graph[ver][i]] == 0)
        {
            dfs(graph[ver][i], graph, visited);
        }
    }
}

void dfs_iter(int n, vector<int> graph[], int ver)
{
    int i;
    int node;
    bool visit[n];
    for (i = 0; i < n; i++)
    {
        visit[i] = false;
    }
    stack<int> s;
    s.push(ver);
    cout << "\n\nItreative method of DFS traversal:\n";
    while (!s.empty())
    {
        node = s.top();
        s.pop();
        if (visit[node] == false)
        {
            visit[node] = true;
            cout << node << " ";
            for (i = graph[node].size() - 1; i >= 0; i--)
            {
                s.push(graph[node][i]);
            }
        }
    }
}

int main()
{
    int n, e, i, a, b;
    cout << "No.of nodes: ";
    cin >> n;
    vector<int> adj_list[n];
    cout << "No.of edges: ";
    cin >> e;

    int visited[n] = {0};
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (i = 0; i < e; i++)
    {
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;

        list(adj_list, a, b);
    }
    print_list(adj_list, n);
    cout << "\n\nVertex to start traversal: ";
    cin >> e;
    dfs(e, adj_list, visited);
    cout << "DFS traversal(recursive method): ";
    for (i = 0; i < dfs_trav.size(); i++)
    {
        cout << dfs_trav[i] << "  ";
    }
    dfs_iter(n, adj_list, e); // Iterative
    return 0;
}