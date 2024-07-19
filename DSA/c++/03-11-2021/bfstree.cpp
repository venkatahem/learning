#include <iostream>
#include <list>

using namespace std;

struct bfsTree
{
    int data;
    bfsTree *child[100];
};
bfsTree *root = NULL;

void preorder(bfsTree *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    for (int i = 0; i < 100; i++)
    {
        if (node->child[i] != NULL)
        {
            preorder(node->child[i]);
        }
        else
        {
            break;
        }
    }
}

bfsTree *insertChildren(int k, bfsTree *root, int ver)
{

    if ((root) != NULL)
    {
        if (ver == root->data)
        {
            for (int j = 0; j < 100; j++)
            {
                if (root->child[j] == NULL)
                {
                    bfsTree *temp = new bfsTree;
                    temp->data = k;
                    for (int i = 0; i < 100; i++)
                    {
                        temp->child[i] = NULL;
                    }
                    root->child[j] = temp;
                    break;
                }
            }
        }
        for (int i = 0; root->child[i] != NULL; i++)
        {
            insertChildren(k, root->child[i], ver);
        }
    }
    return root;
}

class Graph
{
    int V;

    list<int> *adj;

public:
    Graph(int V);

    void addEdge(int v, int w);

    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int des)
{
    adj[src].push_back(des);
    adj[des].push_back(src);
}

void Graph::BFS(int ver)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[ver] = true;
    queue.push_back(ver);

    list<int>::iterator i;

    while (!queue.empty())
    {
        ver = queue.front();
        cout << ver << " ";
        queue.pop_front();

        for (i = adj[ver].begin(); i != adj[ver].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                insertChildren(*i, root, ver);
            }
        }
    }
}

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    // g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 4);
    g.addEdge(2, 1);
    // g.addEdge(2, 0);
    // g.addEdge(3, 0);
    // g.addEdge(4, 2);

    cout << "Graph size: 5" << endl;
    cout << "Select the vertex to start Breadth First Traversal: ";
    int vertex;
    cin >> vertex;
    root = new bfsTree;
    root->data = vertex;
    for (int i = 0; i < 100; i++)
    {
        root->child[i] = NULL;
    }
    cout << "\nBreadth First Traversal: ";
    g.BFS(vertex);
    cout << "\n\nPre-order traversal of the BF Spanning Tree: ";
    preorder(root);

    return 7;
}