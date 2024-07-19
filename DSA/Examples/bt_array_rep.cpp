#include <iostream>
using namespace std;

void set_left(int tree[], int val, int parent)
{
    tree[2 * parent + 1] = val;
}

void set_right(int tree[], int val, int parent)
{
    tree[2 * parent + 2] = val;
}

int main()
{
    int N = 15;
    int tree[N] = {0};

    tree[0] = 1;
    set_left(tree, 2, 0);
    set_right(tree, 3, 0);
    set_left(tree, 4, 1);
    set_right(tree, 5, 1);
    set_left(tree, 6, 2);
    set_right(tree, 7, 2);
    set_right(tree, 8, 6);

    for (int i = 0; i < N; i++)
    {
        if (tree[i] == 0)
            cout << "-"
                 << " ";
        else
            cout << tree[i] << " ";
    }
    return 0;
}
