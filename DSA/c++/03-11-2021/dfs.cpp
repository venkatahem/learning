#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct list
{
    struct node *head;
};

struct graph
{
    int ver;
    struct list *array;
};

node *createNode(int x)
{
    node *newN = (struct node *)malloc(sizeof(struct node));
    newN->data = x;
    newN->next = NULL;
    return newN;
}

graph *createGraph(int v)
{
    int i;
    graph *newG = (struct graph *)malloc(sizeof(struct graph));
    newG->ver = v;
    newG->array = (struct list *)malloc(sizeof(struct list) * v);
    for (i = 0; i < v; i++)
    {
        newG->array[i].head = NULL;
    }

    return newG;
}

void addEdge(graph *g, int vertices[], int src, int des, int v)
{
    int i, temp1, temp2, flag = 0;
    for (i = 0; i < v; i++)
    {
        if (vertices[i] == src)
        {
            temp1 = i;
            flag++;
        }
        else if (vertices[i] == des)
        {
            temp2 = i;
            flag++;
        }

        if (flag == 2)
        {
            break;
        }
    }
    struct node *temp = createNode(temp2);

    temp->next = g->array[temp1].head;
    g->array[temp1].head = temp;
}

void dfs(int ver[], int v, graph *g, int vertex)
{
    int i, j, k, temp, temp1, flag = 1;
    int visited[v];
    node *cur;
    stack<int> s;
    for (i = 0; i < v; i++)
    {
        visited[i] = -1;
    }
    for (i = 0; i < v; i++)
    {
        if (ver[i] == vertex)
        {
            temp = i;
            break;
        }
    }
    s.push(temp);
    j = 0;
    visited[0] = temp;
    cur = g->array[temp].head;
    while (!s.empty())
    {
        while (cur != NULL)
        {
            // if (cur->next != NULL)
            //{
            for (i = 0; i < v; i++)
            {
                if (visited[i] == cur->data)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                j++;
                visited[j] = cur->data;
                if (s.top() != temp)
                {
                    s.push(temp);
                }
                temp = cur->data;
                cur = g->array[temp].head;
                // flag=0;
            }
            else
            {
                cur = cur->next;
                flag = 1;
            }
            //}
        }
    }
}

int main()
{
    int s, i, x, src, des;
    cout << "No.of vertices: ";
    cin >> s;
    int vert[s];
    cout << "Enter the vertices: \n";
    for (i = 0; i < s; i++)
    {
        cout << "Vertex - " << i + 1 << ": ";
        cin >> vert[i];
    }
    graph *myGraph = createGraph(s);
    do
    {
        cout << "\n1--> Add an edge\n2--> DFS\n3--> Exit\nChoose: ";
        cin >> x;
        if (x = 1)
        {
            cout << "Source: ";
            cin >> src;
            cout << "Destination: ";
            cin >> des;
            addEdge(myGraph, vert, src, des, s);
        }
        if (x == 2)
        {
        }
    } while (x != 0);
}
