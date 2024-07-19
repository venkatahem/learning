#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sol;

void subset(vector<int> set, int pos, int sum, int total, vector<int> temp)
{
    if (sum > total)
    {
        return;
    }
    if (sum == total)
    {
        sol.push_back(temp);
        return;
    }
    for (int i = pos; i < set.size(); i++)
    {
        if (sum + set[i] <= total)
        {
            int temp_sum = sum + set[i];
            int j = i + 1;
            vector<int> temp1 = temp;
            temp1.push_back(set[i]);
            subset(set, j, temp_sum, total, temp1);
        }
    }
}

int main()
{
    int i, j, n, temp;
    vector<int> set;

    cout << "No.of elements: ";
    cin >> n;
    cout << "Input the elements: \n";
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        set.push_back(temp);
    }
    cout << "\nEnter the sum to be found: ";
    cin >> temp;

    subset(set, 0, 0, temp, {});

    cout << "\nPossible solution(s):\n";
    for (i = 0; i < sol.size(); i++)
    {
        cout << "{ ";
        for (j = 0; j < sol[i].size(); j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << "}\n";
    }
    return 0;
}