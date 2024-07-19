#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int main()
{
    int N, m;
    // cin >> N>> m;
    N = 7;
    vector<node> edges;
    vector<int> wei;
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     edges.push_back(node(u, v, wt));
    // }
    edges.push_back(node(1, 2, 28));
    edges.push_back(node(1, 6, 10));
    edges.push_back(node(6, 5, 25));
    edges.push_back(node(5, 7, 24));
    edges.push_back(node(7, 4, 18));
    edges.push_back(node(5, 4, 22));
    edges.push_back(node(4, 3, 12));
    edges.push_back(node(3, 2, 16));
    edges.push_back(node(7, 2, 14));
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0; i < N; i++)
        parent[i] = i;
    vector<int> rank(N, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            wei.push_back(it.wt);
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << "Cost: " << cost << endl;
    int i = 0;
    cout << "Edge    Weight\n";
    for (auto it : mst)
    {
        cout << it.first << " - " << it.second;
        cout << " => " << wei[i] << endl;
        i++;
    }

    return 0;
}