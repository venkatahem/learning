#include <iostream>
#include <stdlib.h>

using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

static int flag = 0;

struct tree *root = NULL;
struct tree *inSuc = NULL;

struct tree *createNode(int data)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << "  ";
    inOrder(root->right);
}

tree *search(tree *root, int data)
{
    if (root != NULL)
    {
        if (root->data == data)
        {
            return root;
        }
        else
        {
            tree *foundNode = search(root->left, data);
            if (foundNode == NULL)
            {
                foundNode = search(root->right, data);
            }
            return foundNode;
        }
    }
    else
    {
        return NULL;
    }
}

tree *searchPar(tree *root, int data)
{
    if (root != NULL)
    {
        if ((root->left->data == data) || (root->right->data == data))
        {
            return root;
        }
        else
        {
            tree *foundNode = search(root->left, data);
            if (foundNode == NULL)
            {
                foundNode = search(root->right, data);
            }
            return foundNode;
        }
    }
    else
    {
        return NULL;
    }
}

void inorderSearch(tree *root, int data)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    if (flag == 1)
    {
        inSuc = root;
    }
    if (root->data == data)
    {
        flag = 1;
    }
    //cout << root->data << "  ";
    inOrder(root->right);
}

void insert(int data, int node, int pos)
{
    int x;
    if (root == NULL)
    {
        cout << "Creating root node\n";
        root = createNode(data);
    }
    else
    {
        struct tree *temp = search(root, node);
        if (temp == NULL)
        {
            cout << "\nNode not found";
        }
        if (pos == 1)
        {
            if (temp->left != NULL)
            {
                cout << "\nNode is not empty!!!\n";
            }
            else
            {
                temp->left = createNode(data);
            }
        }
        else if (pos == 2)
        {
            if (temp->right != NULL)
            {
                cout << "\nNode is not empty!!!\n";
            }
            else
            {
                temp->right = createNode(data);
            }
        }
    }
}

void delroot()
{
    struct tree *temp = root;
    if ((root->left == NULL) && (root->right == NULL))
    {
        root = NULL;
        free(temp);
    }
    else if (((root->left == NULL) && (root->right != NULL)) || ((root->left != NULL) && (root->right == NULL)))
    {
        if (root->left != NULL)
        {
            root = root->left;
        }
        else if (root->right != NULL)
        {
            root = root->right;
        }
    }
    else if ((root->left != NULL) && (root->right != NULL))
    {
        flag = 0;
        inorderSearch(root, root->data);
        if (inSuc != NULL)
        {
            cout << "\nInserting it's inorder successor in it's place: " << inSuc->data << endl;
            root->data = inSuc->data;

            if ((inSuc->left == NULL) && (inSuc->right == NULL))
            {
                struct tree *parent = searchPar(root, inSuc->data);
                if (parent->left->data == inSuc->data)
                {
                    parent->left = NULL;
                    free(inSuc);
                    inSuc = NULL;
                }
                else if (parent->right->data == inSuc->data)
                {
                    parent->right = NULL;
                    free(inSuc);
                    inSuc = NULL;
                }
            }
            else if ((inSuc->left != NULL) || (inSuc->right != NULL))
            {
                struct tree *parent = searchPar(root, inSuc->data);
                if (inSuc->left != NULL)
                {
                    if (parent->left->data == inSuc->data)
                    {
                        parent->left = inSuc->left;
                        free(inSuc);
                        inSuc = NULL;
                    }
                    else if (parent->right->data == inSuc->data)
                    {
                        parent->right = inSuc->left;
                        free(inSuc);
                        inSuc = NULL;
                    }
                }
                if (inSuc->right != NULL)
                {
                    if (parent->left->data == inSuc->data)
                    {
                        parent->left = inSuc->right;
                        free(inSuc);
                        inSuc = NULL;
                    }
                    else if (parent->right->data == inSuc->data)
                    {
                        parent->right = inSuc->right;
                        free(inSuc);
                        inSuc = NULL;
                    }
                }
            }
            cout << "\nDeletion done" << endl;
        }
    }
}

void del(int node)
{
    if (root != NULL)
    {
        struct tree *delNode = search(root, node);
        if (delNode != NULL)
        {
            if ((delNode->left == NULL) && (delNode->right == NULL))
            {
                struct tree *parent = searchPar(root, node);
                if (parent->left->data == node)
                {
                    parent->left = NULL;
                    free(delNode);
                }
                else if (parent->right->data == node)
                {
                    parent->right = NULL;
                    free(delNode);
                }
            }
            else if (((delNode->left == NULL) && (delNode->right != NULL)) || ((delNode->left != NULL) && (delNode->right == NULL)))
            {
                struct tree *parent = searchPar(root, node);
                if (delNode->left != NULL)
                {
                    if (parent->left->data == node)
                    {
                        parent->left = delNode->left;
                        free(delNode);
                    }
                    else if (parent->right->data == node)
                    {
                        parent->right = delNode->left;
                        free(delNode);
                    }
                }
                if (delNode->right != NULL)
                {
                    if (parent->left->data == node)
                    {
                        parent->left = delNode->right;
                        free(delNode);
                    }
                    else if (parent->right->data == node)
                    {
                        parent->right = delNode->right;
                        free(delNode);
                    }
                }
            }
            else if ((delNode->left != NULL) && (delNode->right != NULL))
            {
                flag = 0;
                inorderSearch(root, node);
                if (inSuc != NULL)
                {
                    cout << "\nInserting it's inorder successor in it's place: " << inSuc->data << endl;
                    delNode->data = inSuc->data;

                    if ((inSuc->left == NULL) && (inSuc->right == NULL))
                    {
                        struct tree *parent = searchPar(root, inSuc->data);
                        if (parent->left->data == node)
                        {
                            parent->left = NULL;
                            free(inSuc);
                            inSuc = NULL;
                        }
                        else if (parent->right->data == node)
                        {
                            parent->right = NULL;
                            free(inSuc);
                            inSuc = NULL;
                        }
                    }
                    else if ((inSuc->left != NULL) || (inSuc->right != NULL))
                    {
                        struct tree *parent = searchPar(root, inSuc->data);
                        if (inSuc->left != NULL)
                        {
                            if (parent->left->data == node)
                            {
                                parent->left = inSuc->left;
                                free(inSuc);
                                inSuc = NULL;
                            }
                            else if (parent->right->data == node)
                            {
                                parent->right = inSuc->left;
                                free(inSuc);
                                inSuc = NULL;
                            }
                        }
                        if (inSuc->right != NULL)
                        {
                            if (parent->left->data == node)
                            {
                                parent->left = inSuc->right;
                                free(inSuc);
                                inSuc = NULL;
                            }
                            else if (parent->right->data == node)
                            {
                                parent->right = inSuc->right;
                                free(inSuc);
                                inSuc = NULL;
                            }
                        }
                    }
                    cout << "\nDeletion done" << endl;
                }
                else
                {
                    cout << "\nDeletion not done" << endl;
                }
            }
        }
        else
        {
            cout << "\nNode not found" << endl;
        }
    }
}

int main()
{
    int data, x, y, z, pos, temp;
    do
    {
        cout << "\n1 --> Insert\n2 --> Display\n3 --> Delete\n0--> Exit\nChoose: ";
        cin >> x;
        if (x == 1)
        {
            if (root == NULL)
            {
                cout << "\nEnter node data: ";
                cin >> y;
                insert(y, 0, 0);
            }
            else
            {
                cout << "\nEnter node data: ";
                cin >> y;
                inOrder(root);
                cout << "\nSelect node to insert: ";
                cin >> z;
                cout << "\nPosition (1 --> Left, 2 --> Right):";
                cin >> pos;
                insert(y, z, pos);
            }
        }
        else if (x == 2)
        {
            cout << "\nInorder: \n";
            inOrder(root);
        }
        else if (x == 3)
        {
            cout << "\nWhich node to delete: ";
            cin >> y;
            if (root->data == y)
            {
                delroot();
            }
            else
            {
                del(y);
            }
            inOrder(root);
        }
    } while (x != 0);
}