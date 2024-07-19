#include <iostream>
#include <stdlib.h>

using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
node *troot;
node *newNode(int data)
{
    node *newnode = (struct node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void check(int search, int val, node *root, int c)
{
    if (root->data == search)
    {
        if (c == 1 && root->left == NULL)
        {
            node *t = newNode(val);
            root->left = t;
        }
        else if (c == 2 && root->right == NULL)
        {
            node *t = newNode(val);
            root->right = t;
        }
        else
        {
            cout << "\nNode not empty\n";
        }
    }
}
node *inorderInsert(int search, int val, node *root, char c)
{
    if ((root) != NULL)
    {
        inorderInsert(search, val, root->left, c);
        check(search, val, root, c);
        inorderInsert(search, val, root->right, c);
    }
    return root;
}
node *deleteNode(int val, node *root)
{
    if (root->data == val)
    {
        node *t = root->right;
        if (t == NULL)
        {
            return NULL;
        }
        else if (t->left == NULL)
        {
            root->data = t->data;
            if (t->right)
            {
                root->right = t->right;
            }
            else
            {
                root->right = NULL;
            }
        }
        else
        {
            node *prev;
            while (t->left)
            {
                prev = t;
                t = t->left;
            }
            root->data = t->data;
            prev->left = NULL;
        }
    }
    return root;
}
node *inorderDelete(int val, node *root)
{
    if (root != NULL)
    {
        inorderDelete(val, root->left);
        if (root->left && (root->left)->data == val && (root->left)->left == NULL && (root->left)->right == NULL)
        {
            root->left = NULL;
        }
        if (root->right && (root->right)->data == val && (root->right)->left == NULL && (root->right)->right == NULL)
        {
            root->right = NULL;
        }
        if ((root->left && (root->left)->data == val))
        {
            if (((root->left)->left && (root->left)->right == NULL))
            {
                node *temp = root;
                temp = root->left;
                root->left = temp->left;
                temp->left = NULL;
            }
            if (((root->left)->right && (root->left)->left == NULL))
            {
                node *temp = root;
                temp = root->left;
                root->left = temp->right;
                temp->right = NULL;
            }
        }
        if ((root->right && (root->right)->data == val))
        {
            if (((root->right)->left && (root->right)->right == NULL))
            {
                node *temp = root;
                temp = root->right;
                root->right = temp->left;
                temp->left = NULL;
            }
            if (((root->right)->right && (root->right)->left == NULL))
            {
                node *temp = root;
                temp = root->right;
                root->right = temp->right;
                temp->right = NULL;
            }
        }
        if (root->left && root->right)
        {
            root = deleteNode(val, root);
        }
        inorderDelete(val, root->right);
    }
    return root;
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int main()
{
    node *root;
    troot = root;
    int y;
    while (1)
    {
        cout << "\n1.Insert root\n2.Insert\n3.Delete\n4.Inorder Traversal\n5.Quit\nChoose: ";
        cin >> y;
        switch (y)
        {
        case 1:
            int rval;
            cout << "Enter root value\n";
            cin >> rval;
            root = newNode(rval);
            break;
        case 2:

            int insert;
            cout << "\nEnter the value to inserted: ";
            cin >> insert;
            cout << "\nEnter the parent node of the value inserted: ";
            int parent;
            cin >> parent;
            cout << "\nLeft or right child?(1->left, 2->right): ";
            int x;
            cin >> x;
            root = inorderInsert(parent, insert, root, x);
            cout << "\n";
            inOrder(root);
            break;
        case 3:
            cout << "\nEnter the value to be deleted: ";
            int d;
            cin >> d;
            root = inorderDelete(d, root);
            inOrder(root);
            break;
        case 4:
            inOrder(root);
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
    return 7;
}
