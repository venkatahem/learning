#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct tree
{
    int id;
    string name;
    int marks;
    tree *left;
    tree *right;
};
tree *root = NULL;

tree *createNode(int x, int m, string n)
{
    tree *newNode = (struct tree *)malloc(sizeof(struct tree));
    newNode->id = x;
    newNode->marks = m;
    newNode->name = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

tree *insert(tree *root, int x, int m, string n)
{
    if (root == NULL)
    {
        return createNode(x, m, n);
    }

    if (root->id > x)
    {
        root->left = insert(root->left, x, m, n);
    }
    else
    {
        root->right = insert(root->right, x, m, n);
    }
    return root;
}

tree *search(tree *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->id == x)
    {
        return root;
    }

    if (root->id > x)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

tree *inoderSucc(tree *root)
{
    tree *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

tree *delIN(tree *root, int x)
{
    if (root->id > x)
    {
        root->left = delIN(root->left, x);
    }
    else if (root->id < x)
    {
        root->right = delIN(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tree *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            tree *temp = inoderSucc(root->right);
            root->id = temp->id;
            root->name = temp->name;
            root->marks = temp->marks;
            root->right = delIN(root->right, temp->id);
        }
    }
    return root;
}

void inorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << "\n";
    cout << "ID: " << root->id << endl;
    cout << "Name: " << root->name << endl;
    cout << "Marks: " << root->marks << endl;
    inorder(root->right);
}

int main()
{
    int id;
    int x, y;
    int marks;
    int flag = 0;
    string name;
    tree *temp;
    do
    {
        cout << "\n1-->Insert\n2-->Search\n3-->Delete\n4-->Display\n0-->Exit\nChoose: ";
        cin >> x;
        if (x == 1)
        {
            if (flag == 0)
            {
                cout << "What is the total strength of the class?: ";
                cin >> y;
                cout << "Enter the details of the student with ID: " << y / 2 << endl;
                cout << "Name: ";
                cin >> name;
                cout << "Marks: ";
                cin >> marks;
                cout << endl;
                root = insert(root, (y / 2), marks, name);
                flag++;
            }
            else
            {
                cout << "\nEnter student ID: ";
                cin >> id;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter marks: ";
                cin >> marks;
                insert(root, id, marks, name);
            }
        }
        else if (x == 2)
        {
            if (root != NULL)
            {

                cout << "\nStudent id: ";
                cin >> id;
                temp = search(root, id);
                if (temp != NULL)
                {
                    cout << "\n";
                    cout << "ID: " << temp->id << endl
                         << "Name: " << temp->name << endl
                         << "Marks: " << temp->marks << endl;
                }
                else
                {
                    cout << "\nStudent details not found" << endl;
                }
            }
            else
            {
                cout << "\nNo data to saerch" << endl;
            }
        }
        else if (x == 3)
        {
            if (root != NULL)
            {
                cout << "\nStudent ID to delete: ";
                cin >> id;
                temp = search(root, id);
                if (temp == NULL)
                {
                    cout << "\nID doesn't exist" << endl;
                }
                else
                {
                    root = delIN(root, id);
                    if (root == NULL)
                    {
                        flag = 0;
                    }
                    cout << "\nDeletion done..........." << endl;
                }
            }
            else
            {
                cout << "\nNo data to delete" << endl;
            }
        }
        else if (x == 4)
        {
            if (root != NULL)
            {
                cout << "Details of all student: " << endl;
                inorder(root);
            }
            else
            {
                cout << "\nNo data to display" << endl;
            }
        }
    } while (x != 0);

    return 7;
}