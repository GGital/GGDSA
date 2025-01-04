#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Stack
{
    int size;
    node *top;
} stack;

stack *create_s()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

void push(stack *s, int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->next = s->top;
    s->top = new;
    s->size++;
}

void pop(stack *s)
{
    if (!s->top)
        return;
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
}

int peek(stack *s)
{
    if (s->size <= 0)
    {
        printf("Stack is empty!\n");
        return -999;
    }
    return s->top->data;
}

int main()
{
    stack *s = create_s();
    push(s, 5);
    printf("%d\n", peek(s));
    push(s, 10);
    printf("%d\n", peek(s));
    pop(s);
    printf("%d\n", peek(s));
    pop(s);
    printf("%d\n", peek(s));
    return 0;
}