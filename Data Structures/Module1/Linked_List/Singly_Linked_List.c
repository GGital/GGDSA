#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_ll()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void display(struct node *head)
{
    if (head == NULL)
        return;
    printf("%d ", head->data);
    display(head->next);
}

struct node *insert_beg(struct node *head, int val)
{
    struct node *temp_node = (struct node *)malloc(sizeof(struct node));
    temp_node->data = val;
    temp_node->next = head;
    return temp_node;
}

void insert_end(struct node *head, int val)
{
    struct node *last = head;
    while (last->next != NULL)
        last = last->next;
    struct node *temp_node = (struct node *)malloc(sizeof(struct node));
    temp_node->data = val;
    temp_node->next = NULL;
    last->next = temp_node;
}

void insert_before(struct node *head, int val, int index)
{
    int i = 0;
    struct node *last = NULL;
    while (i < index)
    {
        last = head;
        head = head->next;
        i++;
    }
    struct node *temp_node = (struct node *)malloc(sizeof(struct node));
    temp_node->data = val;
    temp_node->next = head;
    last->next = temp_node;
}

void insert_after(struct node *head, int val, int index)
{
    int i = 0;
    struct node *last = NULL;
    while (i < index && head->next != NULL)
    {
        last = head;
        head = head->next;
        i++;
    }
    struct node *temp_node = (struct node *)malloc(sizeof(struct node));
    temp_node->data = val;
    temp_node->next = head->next;
    head->next = temp_node;
}

void delete_beg(struct node **head_ref)
{
    if (*head_ref == NULL)
        return;

    struct node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void delete_end(struct node **head_ref)
{
    if (*head_ref == NULL)
        return;
    struct node **last = NULL;
    while ((*head_ref)->next != NULL)
    {
        last = head_ref;
        head_ref = &(*head_ref)->next;
    }
    struct node *temp = *head_ref;
    (*last)->next = NULL;
    free(temp);
}

void delete_node(struct node **head_ref, int index)
{
    int i = 0;
    if (*head_ref == NULL)
        return;
    struct node **last = NULL;
    while (i < index && (*head_ref)->next != NULL)
    {
        last = head_ref;
        head_ref = &(*head_ref)->next;
        i++;
    }
    struct node *temp = *head_ref;
    if (last != NULL)
        (*last)->next = (*head_ref)->next;
    free(temp);
}

void delete_after(struct node **head_ref, int index)
{
    if (*head_ref == NULL)
        return;

    struct node *current = *head_ref;
    int i = 0;
    while (i < index && current != NULL)
    {
        current = current->next;
        i++;
    }
    if (current == NULL || current->next == NULL)
        return;

    struct node *temp = current->next;
    current->next = temp->next;

    free(temp);
}

void delete_list(struct node *head)
{
    free(head);
}

int main()
{
    struct node *head = create_ll();
    printf("Created Linked list\n");
    // display(head);
    head = insert_beg(head, 5);
    head = insert_beg(head, 15);
    insert_end(head, 15);
    display(head);
    printf("\n");
    insert_before(head, 10, 1);
    display(head);
    printf("\n");
    insert_after(head, 20, 1);
    display(head);
    printf("\n");
    // delete_beg(&head);
    // delete_beg(&head);
    delete_end(&head);
    display(head);
    printf("\n");
    insert_before(head, 10, 1);
    insert_before(head, 10, 1);
    insert_before(head, 10, 1);
    display(head);
    printf("\n");
    delete_node(&head, 1);
    display(head);
    printf("\n");
    delete_after(&head, 5);
    display(head);
    printf("\n");
    delete_list(head);
    return 0;
}