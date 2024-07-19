#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sol;

bool isSafe(vector<vector<int>> board, int row, int col)
{
    int i, j;
    int n = board.size();
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
    for (i = row, j = col; (i < n) && (j >= 0); i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool solveNQ(vector<vector<int>> board, int col)
{
    int n = board.size();
    bool res = false;
    if (col >= n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    temp.push_back(j + 1);
                }
            }
        }
        sol.push_back(temp);
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQ(board, col + 1))
            {
                res = true;
            }

            board[i][col] = 0;
        }
    }

    return res;
}

vector<vector<int>> NQ(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQ(board, 0) == false)
    {
        return {};
    }
    else
    {
        sort(sol.begin(), sol.end());
        return sol;
    }
}

int main()
{
    int n;
    cout << "\nNo.of queens: ";
    cin >> n;
    int x = 0;

    vector<vector<int>> ans = NQ(n);

    cout << "\nPossible solutions\n\n";

    for (int i = 0; i < ans.size(); i++)
    {
        x = 1;
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << "]\t";
        if ((i != 0) && (i % 4 == 0))
        {
            cout << "\n";
        }
    }
    if (x == 0)
    {
        cout << "Nil";
    }

    return 0;
}