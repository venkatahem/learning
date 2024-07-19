#include <iostream>
#include <stdlib.h>

using namespace std;

int size;

// I N S E R T

void insert(int arr[], int data)
{
    int i;
    int x, flag = 0;
    int node;
    if (arr[0] == -1)
    {
        cout << "Inserting as root node";
        arr[0] = data;
    }
    else
    {
        cout << "\nAvailable empty nodes\n";
        for (i = 0; i < size; i++)
        {
            if (arr[i] != -1)
            {
                if ((arr[(2 * (i + 1)) - 1] == -1) && (arr[(2 * (i + 1))] == -1))
                {
                    cout << "\n";
                    cout << arr[i] << " -> Empty left and right nodes";
                    flag = 1;
                }
                else if ((arr[(2 * (i + 1)) - 1] == -1) && (arr[(2 * (i + 1))] != -1))
                {
                    cout << "\n";
                    cout << arr[i] << " -> Empty left node";
                    flag = 1;
                }
                else if ((arr[(2 * (i + 1)) - 1] != -1) && (arr[(2 * (i + 1))] == -1))
                {
                    cout << "\n";
                    cout << arr[i] << " -> Empty right node";
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            cout << "\n\nSelect a node to insert data: ";
            cin >> node;
            cout << "1 --> Left\n2 --> Right\nChoose: ";
            cin >> x;
            for (i = 0; i < size; i++)
            {
                if (arr[i] == node)
                {
                    break;
                }
            }
            if (x == 1)
            {
                if (arr[(2 * (i + 1)) - 1] == -1)
                {
                    arr[(2 * (i + 1)) - 1] = data;
                }
                else
                {
                    cout << "\nNode is not empty!!!";
                }
            }
            else if (x == 2)
            {
                if (arr[(2 * (i + 1))] == -1)
                {
                    arr[(2 * (i + 1))] = data;
                }
                else
                {
                    cout << "\nNode is not empty!!!";
                }
            }
        }
        else
        {
            cout << "\nNo empty nodes";
        }
    }
}

// D E L E T E
void del(int arr[], int data)
{
    int i;
    int flag = 1;
    int temp = -1;

    for (i = (size - 1); i >= 0; i--)
    {
        if (arr[i] != -1)
        {
            if (arr[i] == data)
            {
                arr[i] = -1;
                flag = 0;
                break;
            }
            else
            {
                temp = arr[i];
                arr[i] = -1;
                break;
            }
        }
    }
    if (flag)
    {
        for (i = 0; i < size; i++)
        {
            if (arr[i] == data)
            {
                arr[i] = temp;
                break;
            }
        }
    }
}

// D I S P L A Y

void display(int arr[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == -1)
        {
            cout << " - ";
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
}

// M A I N

int main()
{
    int i;
    int x, y;
    cout << "Enter tree size: ";
    cin >> size;
    int arr[size];
    for (i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
    do
    {
        cout << "\n1 --> Insert\n2 --> Delete\n3 --> Display\n0 --> Exit\nChoose: ";
        cin >> x;
        if (x == 1)
        {
            cout << "Enter data: ";
            cin >> y;
            insert(arr, y);
        }
        else if (x == 3)
        {
            display(arr);
        }
        else if (x == 2)
        {
            if (arr[0] != -1)
            {
                display(arr);
                cout << "\nNode to delete: ";
                cin >> y;
                del(arr, y);
                cout << "\nDeletetion done";
            }
            else
            {
                cout << "\nTree is empty";
            }
        }
    } while (x != 0);

    return 7;
}