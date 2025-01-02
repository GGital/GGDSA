#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct dll
{
    struct node *head;
};

struct dll create_dll()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    struct dll l;
    l.head = head;
    return l;
}

void display(struct dll dl)
{
    struct node *head = dl.head;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_beg(struct dll *dlptr, int val)
{
    struct node *head = dlptr->head;
    struct node *new_head = (struct node *)malloc(sizeof(struct node));
    new_head->data = val;
    new_head->prev = NULL;
    new_head->next = head;
    head->prev = new_head;
    (*dlptr).head = new_head;
}

void insert_end(struct dll *dlptr, int val)
{
    struct node *head = dlptr->head;
    struct node *last = head;
    while (last->next != NULL)
        last = last->next;
    struct node *new_last = (struct node *)malloc(sizeof(struct node));
    new_last->data = val;
    new_last->prev = last;
    new_last->next = NULL;
    last->next = new_last;
}

void insert_after(struct dll *dlptr, int val, int index)
{
    int i = 0;
    struct node *head = dlptr->head;
    while (i < index && head->next != NULL)
    {
        head = head->next;
        i++;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    if (head->next != NULL)
    {
        struct node *next = head->next;
        next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;
        new_node->next = next;
    }
    else
    {
        head->next = new_node;
        new_node->prev = head;
        new_node->next = NULL;
    }
}

void insert_before(struct dll *dlptr, int val, int index)
{
    int i = 0;
    struct node *head = dlptr->head;
    while (i < index && head->next != NULL)
    {
        head = head->next;
        i++;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    if (head->prev != NULL)
    {
        struct node *prev = head->prev;
        prev->next = new_node;
        head->prev = new_node;
        new_node->prev = prev;
        new_node->next = head;
    }
    else
    {
        head->prev = new_node;
        new_node->next = head;
        new_node->prev = NULL;
    }
}

void delete_beg(struct dll *dlptr)
{
    struct node *head = dlptr->head;
    if (head == NULL)
        return;
    dlptr->head = head->next;
    dlptr->head->prev = NULL;
    free(head);
}

void delete_end(struct dll *dlptr)
{
    struct node *head = dlptr->head;
    struct node *last = head;
    if (head == NULL)
        return;
    while (last->next != NULL)
        last = last->next;
    struct node *pre_last = last->prev;
    pre_last->next = NULL;
    free(last);
}

void delete_after(struct dll *dlptr, int index)
{
    struct node *head = dlptr->head;
    if (head == NULL)
        return;
    int i = 0;
    while (i < index && head->next)
    {
        head = head->next;
        i++;
    }
    if (head->next == NULL)
        return;
    if (head->next->next)
    {
        struct node *del = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        del->next = NULL;
        del->prev = NULL;
        free(del);
    }
    else
    {
        struct node *del = head->next;
        head->next = NULL;
        del->next = NULL;
        del->prev = NULL;
        free(del);
    }
}

void delete_before(struct dll *dlptr, int index)
{
    struct node *head = dlptr->head;
    if (head == NULL)
        return;
    int i = 0;
    while (i < index && head->next)
    {
        head = head->next;
        i++;
    }
    if (head->prev == NULL)
        return;
    if (head->prev->prev)
    {
        struct node *del = head->prev;
        head->prev = head->prev->prev;
        head->prev->next = head;
        del->next = NULL;
        del->prev = NULL;
        // printf("check");
        free(del);
    }
    else
    {
        struct node *del = head->prev;
        head->prev = NULL;
        del->next = NULL;
        del->prev = NULL;
        // printf("check");
        (*dlptr).head = head;
        free(del);
    }
}

int main()
{
    struct dll head = create_dll();
    display(head);
    insert_beg(&head, 50);
    insert_beg(&head, 20);
    display(head);
    insert_end(&head, 30);
    display(head);
    insert_after(&head, 5, 2);
    display(head);
    insert_before(&head, 15, 2);
    display(head);
    delete_beg(&head);
    display(head);
    delete_end(&head);
    display(head);
    delete_after(&head, 2);
    display(head);
    delete_before(&head, 1);
    display(head);
    return 0;
}