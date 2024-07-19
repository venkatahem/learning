//Incomplete BT

#include <iostream>
#include <stdlib.h>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

//Preorder

void preOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    preOrder(root->left);
    preOrder(root->right);
}

//Inorder

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

//Postorder

void postOrder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "  ";
}

// Function to Create a New Node

struct tree *createNode(int data)
{
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{

    //              q
    //          /      \
    //         /        \
    //        q1         q2
    //          \
    //           q3
    //

    struct tree *q = createNode(3);
    struct tree *q1 = createNode(2);
    struct tree *q2 = createNode(1);
    q->left = q1;
    q->right = q2;
    struct tree *q3 = createNode(4);
    q1->right = q3;

    cout << "\nPreorder traversal" << endl;
    preOrder(q);
    cout << "\n\nInorder traversal" << endl;
    inOrder(q);
    cout << "\n\nPostorder traversal" << endl;
    postOrder(q);
    cout << "\n\n";

    //              p
    //          /      \
    //         /        \
    //        p1         p2
    //      /   \         \
    //    p3     p4        p5
    //     \
    //     p6

    struct tree *p = createNode(2);
    struct tree *p1 = createNode(1);
    struct tree *p2 = createNode(4);
    p->left = p1;
    p->right = p2;
    struct tree *p3 = createNode(5);
    struct tree *p4 = createNode(6);
    p1->left = p3;
    p1->right = p4;
    struct tree *p5 = createNode(8);
    p2->right = p5;
    struct tree *p6 = createNode(9);

    cout << "\nPreorder traversal" << endl;
    preOrder(p);
    cout << "\n\nInorder traversal" << endl;
    inOrder(p);
    cout << "\n\nPostorder traversal" << endl;
    postOrder(p);

    return 7;
}