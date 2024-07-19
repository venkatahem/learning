#include <iostream>

using namespace std;

#define N 8

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    for (i = row, j = col; (i >= 0) && (j >= 0); i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (i = row, j = col; (i < N) && (j >= 0); i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool solveNQ(int board[N][N], int col)
{
    int i, j;
    if (col >= N)
    {
        return true;
    }

    for (i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQ(board, col + 1))
            {
                return true;
            }
            else
            {
                board[i][col] = 0;
            }
        }
    }
    return false;
}

bool NQ(int board[N][N])
{

    if (solveNQ(board, 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printNQ(int board[N][N])
{
    int i, j;
    cout << "\n"
         << N << " - Queens\n";
    cout << "\nSOLUTION\n\n";
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int x;
    int board[N][N];
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (NQ(board))
    {
        printNQ(board);
    }
    else
    {
        cout << "\nNo possible solution!\n";
    }

    return 0;
}