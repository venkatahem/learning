//Linked Representation of Binary Tree

//
//              2
//             / \
//            /   \
//           1     4
//
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to Create a New Node

struct node *createNode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int main()
{
    int var;

    /*

    //Creating nodes and assignment of left and right nodes

    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data=2;
    p->left = NULL;
    p->right = NULL;

    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    p->data=1;
    p1->left = NULL;
    p1->right = NULL;

    struct node *p2 = (struct node *)malloc(sizeof(struct node));
    p->data=4;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;

    */

    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    p->left = p1;
    p->right = p2;

    return 7;
}