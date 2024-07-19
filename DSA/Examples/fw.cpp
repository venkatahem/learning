#include <iostream>
using namespace std;
#define I 999999
#define N 4
int main()
{
    int i, j, k, A[N][N];
    int graph[N][N] = {{0, 1, I, 5},
                       {I, 0, 2, I},
                       {4, 8, 0, 6},
                       {3, 3, I, 0}};
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                A[i][j] = min(A[i][k] + A[k][j], A[i][j]);
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}
