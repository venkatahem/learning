#include <iostream>
#include <vector>

using namespace std;
void list(vector<int> temp[], int a, int b)
{
    temp[a].push_back(b);
    temp[b].push_back(a);
}
void matrix(vector<vector<int>> temp, int a, int b)
{
    temp[a][b] = 1;
    temp[b][a] = 1;
}
void print_list(vector<int> temp[], int n)
{
    int i, j;

    cout << "\nAdjacency list representation";

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
void print_matrix(vector<vector<int>> temp, int a)
{
    int i, j;
    for (i = 0; i < a; i++)
    {
        cout << "\n";
        for (j = 0; j < a; j++)
        {
            cout << temp[i][j] << " ";
        }
    }
}
int main()
{
    int n, e, i, a, b;
    cout << "No.of nodes: ";
    cin >> n;
    vector<int> adj_list[n];
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));

    cout << "No.of edges: ";
    cin >> e;

    for (i = 0; i < e; i++)
    {
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;

        list(adj_list, a, b);
        // matrix(adj_matrix, a, b);
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    print_list(adj_list, n);
    print_matrix(adj_matrix, n);
    return 0;
}