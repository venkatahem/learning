#include <iostream>

using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

tree *create(int d)
{
    struct tree *temp = new tree();
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

tree *inorder_succ(tree *root)
{
    tree *temp = root;
    while (temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

tree *insert(tree *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

tree *del(tree *root, int d)
{
    if (d < root->data)
    {
        root->left = del(root->left, d);
    }
    else if (d > root->data)
    {
        root->right = del(root->right, d);
    }
    else
    {
        if (root->right == NULL)
        {
            tree *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            tree *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            tree *temp = inorder_succ(root->right);
            // int x = root->data;
            root->data = temp->data;
            // temp->data = x;
            root->right = del(root->right, temp->data);
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
    cout << root->data << "    ";
    inorder(root->right);
}

tree *search(tree *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == x)
    {
        return root;
    }

    if (root->data > x)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

int main()
{
    struct tree *root = NULL;
    // root =
    tree *temp = NULL;
    root = insert(root, 5);
    insert(root, 7);
    insert(root, 3);
    insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 6);
    inorder(root);
    del(root, 3);
    cout << "\n";
    inorder(root);
    temp = NULL;
    temp = search(root, 9);
    if (temp != NULL)
    {
        cout << "\n"
             << temp->data;
    }
    else
    {
        cout << "\nNot found";
    }
    return 7;
}
