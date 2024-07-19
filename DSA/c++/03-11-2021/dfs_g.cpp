#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;

    list<int> *adj;

public:
    Graph(int V);

    void addEdge(int v, int w);

    void DFS_recursive(int ver, bool *visit);
    void DFS_iterative(int ver);
};

Graph::Graph(int V)
{
    this->V = V;

    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFS_recursive(int ver, bool *visit)
{

    bool *nvisit = visit;

    list<int> queue;
    nvisit[ver] = true;
    cout << ver << " ";

    list<int>::iterator i;
    for (i = adj[ver].begin(); i != adj[ver].end(); ++i)
    {
        if (!nvisit[*i])
        {
            DFS_recursive(*i, nvisit);
        }
    }
}

void Graph::DFS_iterative(int ver)
{
    bool *visit = new bool[V];
    for (int i = 0; i < V; i++)
        visit[i] = false;

    list<int> stack;

    stack.push_front(ver);

    list<int>::reverse_iterator i;

    while (!stack.empty())
    {
        ver = stack.front();

        stack.pop_front();

        if (!visit[ver])
        {
            visit[ver] = true;
            cout << ver << " ";
            for (i = adj[ver].rbegin(); i != adj[ver].rend(); i++)
            {
                stack.push_front(*i);
            }
        }
    }
}

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    // g.addEdge(2, 4);
    // g.addEdge(2, 5);
    // g.addEdge(2, 6);
    // g.addEdge(3, 5);

    cout << "Graph size: 7" << endl;
    cout << "Select the vertex to start Depth First Traversal: ";
    int vertex;
    cin >> vertex;
    cout << "\nDepth First Traversal using recursion: ";

    bool *visit = new bool[8];
    for (int i = 0; i < 8; i++)
        visit[i] = false;
    g.DFS_recursive(vertex, visit);

    cout << "\n\nDepth First Traversal using iteration: ";
    g.DFS_iterative(vertex);

    return 7;
}