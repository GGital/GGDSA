#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct cll
{
    struct node *head;
};

struct cll create_cll()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = head;
    struct cll l;
    l.head = head;
    return l;
}

void display(struct cll cl)
{
    struct node *head = cl.head;
    if (head == NULL)
        return;
    struct node *first = head;
    printf("%d ", head->data);
    head = head->next;
    while (head != first)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_beg(struct cll *clptr, int val)
{
    struct node *head = clptr->head;
    struct node *last = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    while (last->next != head)
        last = last->next;
    last->next = new;
    new->next = head;
    (*clptr).head = new;
}

void insert_end(struct cll cl, int val)
{
    struct node *head = cl.head;
    struct node *last = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    while (last->next != head)
        last = last->next;
    last->next = new;
    new->next = head;
}

void delete_beg(struct cll *clptr)
{
    struct node *head = (*clptr).head;
    struct node *last = head;
    while (last->next != head)
        last = last->next;
    if (head->next == head)
        free(head);
    else
    {
        clptr->head = head->next;
        // printf("%d %d", head, clptr->head);
        last->next = clptr->head;
        free(head);
    }
}

void delete_end(struct cll *clptr)
{
    struct node *head = (*clptr).head;
    struct node *prev = NULL;
    struct node *last = head;
    while (last->next != head)
    {
        prev = last;
        last = last->next;
    }
    if (head->next == head)
        free(head);
    else
    {
        prev->next = head;
        free(last);
    }
}

int main()
{
    struct cll head = create_cll();
    display(head);
    insert_beg(&head, 55);
    insert_beg(&head, 110);
    display(head);
    insert_end(head, 55);
    display(head);
    delete_beg(&head);
    display(head);
    delete_end(&head);
    display(head);
    return 0;
}