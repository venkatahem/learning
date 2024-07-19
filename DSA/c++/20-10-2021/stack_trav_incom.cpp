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

struct stack
{
    struct tree *address;
    struct stack *next;
};

struct stack *head = NULL;

void push(tree *data)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->address = data;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void pop()
{
    if (head != NULL)
    {
        head = head->next;
    }
}

//Preorder

void preOrder(tree *root)
{
    push(root);
    struct tree *cur;
    while (head != NULL)
    {
        cur = head->address;
        cout << " " << cur->data << " ";
        pop();
        if (cur->right != NULL)
        {
            push(cur->right);
        }

        if (cur->left != NULL)
        {
            push(cur->left);
        }
    }
}

//Inorder

void inOrder(tree *root)
{
    tree *cur = root;

    while ((cur != NULL) || (head != NULL))
    {
        if (cur != NULL)
        {
            push(cur);
            cur = cur->left;
        }
        else
        {
            cur = head->address;
            pop();
            cout << " " << cur->data << " ";
            cur = cur->right;
        }
    }
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
    return 7;
}