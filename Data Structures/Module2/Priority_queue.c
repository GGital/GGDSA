#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

typedef struct priority_queue
{
    node *root;
} priority_queue;

priority_queue *create_pq()
{
    priority_queue *new = (priority_queue *)malloc(sizeof(priority_queue));
    new->root = NULL;
    return new;
}

node *create_node(int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node *merge(node *h1, node *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;
    if (h1->data < h2->data)
    {
        node *temp = h1;
        h1 = h2;
        h2 = temp;
    }

    h1->right = merge(h1->right, h2);

    node *temp = h1->left;
    h1->left = h1->right;
    h1->right = temp;

    return h1;
}

void insert(int val, priority_queue *pq)
{
    node *new = create_node(val);
    pq->root = merge(pq->root, new);
}

int peek(priority_queue *pq)
{
    if (pq->root)
        return pq->root->data;
}

void pop(priority_queue *pq)
{
    if (pq->root)
    {
        node *left = pq->root->left;
        node *right = pq->root->right;
        free(pq->root);
        pq->root = merge(left, right);
    }
}

void pre_order(node *tree)
{
    if (!tree)
        return;
    printf("%d ", tree->data);
    pre_order(tree->left);
    pre_order(tree->right);
}

void in_order(node *tree)
{
    if (!tree)
        return;
    in_order(tree->left);

    printf("%d ", tree->data);
    in_order(tree->right);
}

int main()
{
    priority_queue *pq = create_pq();
    insert(5, pq);
    insert(10, pq);
    insert(30, pq);
    insert(15, pq);
    insert(20, pq);
    printf("%d\n", peek(pq));
    in_order(pq->root);
    printf("\n");
    pop(pq);
    printf("%d\n", peek(pq));
    in_order(pq->root);
    return 0;
}