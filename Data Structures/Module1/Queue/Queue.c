#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Queue
{
    int size;
    node *front;
    node *rear;
} queue;

queue *create()
{
    queue *new = (queue *)malloc(sizeof(queue));
    new->size = 0;
    new->front = NULL;
    new->rear = NULL;
}

void enqueue(queue *q, int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    if (q->size == 0)
    {
        q->front = new;
        q->rear = new;
        q->rear->next = NULL;
        q->size++;
    }
    else
    {
        q->rear->next = new;
        q->rear = new;
        q->rear->next = NULL;
        q->size++;
    }
}

void dequeue(queue *q)
{
    if (q->size == 0 || !q->front)
        return;
    node *del = q->front;
    q->front = q->front->next;
    free(del);
    q->size--;
}

int qsize(queue *q)
{
    return q->size;
}

int peek(queue *q)
{
    if (!q->front)
    {
        printf("Queue is empty!\n");
        return -999;
    }
    return q->front->data;
}

int main()
{
    queue *q = create();
    enqueue(q, 5);
    printf("%d\n", peek(q));
    dequeue(q);
    printf("%d\n", peek(q));
    return 0;
}