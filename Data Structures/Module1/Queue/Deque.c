#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Deque
{
    int size;
    node *left;
    node *right;
} deque;

deque *create()
{
    deque *new = (deque *)malloc(sizeof(deque));
    new->size = 0;
    new->left = NULL;
    new->right = NULL;
}

void front_enqueue(deque *q, int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    if (q->size == 0)
    {
        q->left = new;
        q->right = new;
        q->right->next = NULL;
        q->size++;
    }
    else
    {
        new->next = q->left;
        q->left = new;
        q->size++;
    }
}

void back_enqueue(deque *q, int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    if (q->size == 0)
    {
        q->left = new;
        q->right = new;
        q->right->next = NULL;
        q->size++;
    }
    else
    {
        q->right->next = new;
        q->right = new;
        q->right->next = NULL;
        q->size++;
    }
}

void front_dequeue(deque *q)
{
    if (q->size == 0 || !q->left)
        return;
    node *del = q->left;
    q->left = q->left->next;
    free(del);
    q->size--;
}

void back_dequeue(deque *q)
{
    if (q->size == 0 || !q->right)
        return;
    node *del = q->right;
    node *pre_last = q->left;
    while (pre_last->next != q->right)
        pre_last = pre_last->next;
    q->right = pre_last;
    free(del);
    q->size--;
}

int qsize(deque *q)
{
    return q->size;
}

int front_peek(deque *q)
{
    if (!q->left)
    {
        printf("Queue is empty!\n");
        return -999;
    }
    return q->left->data;
}

int back_peek(deque *q)
{
    if (!q->right)
    {
        printf("Queue is empty!\n");
        return -999;
    }
    return q->right->data;
}

int main()
{
    deque *q = create();
    front_enqueue(q, 10);
    front_enqueue(q, 20);
    printf("%d\n", front_peek(q));
    printf("%d\n", back_peek(q));
    back_dequeue(q);
    printf("%d\n", front_peek(q));
    back_enqueue(q, 15);
    printf("%d\n", back_peek(q));
    front_dequeue(q);
    printf("%d\n", front_peek(q));
    front_dequeue(q);
    printf("%d\n", front_peek(q));
    return 0;
}
