#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

typedef struct Priority_queue
{
    int *arr;
    int size;
    int capacity;
} priority_queue;

priority_queue *create_pq(int capacity)
{
    priority_queue *new = (priority_queue *)malloc(sizeof(priority_queue));
    new->arr = (int *)malloc(capacity * sizeof(int));
    new->size = 0;
    new->capacity = capacity;
    return new;
}

void insert(int val, priority_queue *pq)
{
    if (pq->size == pq->capacity)
    {
        printf("Priority Queue is full!\n");
        return;
    }
    pq->arr[pq->size] = val;
    int i = pq->size;
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (pq->arr[parent] > pq->arr[i])
            break;
        int temp = pq->arr[parent];
        pq->arr[parent] = pq->arr[i];
        pq->arr[i] = temp;
        i = parent;
    }
    pq->size++;
}

void pop(priority_queue *pq)
{
    if (pq->size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    int i = 0;
    while (2 * i + 1 < pq->size)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int max = i;
        if (pq->arr[left] > pq->arr[max])
            max = left;
        if (right < pq->size && pq->arr[right] > pq->arr[max])
            max = right;
        if (max == i)
            break;
        int temp = pq->arr[i];
        pq->arr[i] = pq->arr[max];
        pq->arr[max] = temp;
        i = max;
    }
}

int peek(priority_queue *pq)
{
    if (pq->size == 0)
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    return pq->arr[0];
}

int main()
{
    priority_queue *pq = create_pq(5);
    insert(50, pq);
    insert(20, pq);
    insert(30, pq);
    insert(40, pq);
    printf("%d\n", peek(pq));
    pop(pq);
    printf("%d\n", peek(pq));
    return 0;
}