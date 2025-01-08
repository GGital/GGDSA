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

typedef struct Binary_Tree
{
    node *root;
} BT;

BT *create_BT()
{
    BT *new = (BT *)malloc(sizeof(BT));
    new->root = NULL;
}

node *create_node(int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
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

void post_order(node *tree)
{
    if (!tree)
        return;
    post_order(tree->left);
    post_order(tree->right);
    printf("%d ", tree->data);
}

node *search_element(node *tree, int val, int left, int right)
{
    if (tree->data == val)
    {
        printf("Left : %d\n", left);
        printf("Right : %d\n", right);
    }
    else if (val > tree->data)
        search_element(tree->right, val, left, right + 1);
    else
        search_element(tree->left, val, left + 1, right);
}

void insert_element(node **treeptr, int val)
{
    if (!(*treeptr))
        (*treeptr) = create_node(val);
    else if (val > (*treeptr)->data)
        insert_element(&(*treeptr)->right, val);
    else
        insert_element(&(*treeptr)->left, val);
}

void delete_element(node **treeptr, int val)
{
    if (!(*treeptr))
        return; // Base case: Element not found.

    if (val < (*treeptr)->data)
    {
        delete_element(&(*treeptr)->left, val); // Search in the left subtree.
    }
    else if (val > (*treeptr)->data)
    {
        delete_element(&(*treeptr)->right, val); // Search in the right subtree.
    }
    else
    {
        // Node to be deleted found.
        node *temp = *treeptr;

        // Case 1: Node has no children (leaf node).
        if (!temp->left && !temp->right)
        {
            free(temp);
            *treeptr = NULL;
        }
        // Case 2: Node has only one child (left or right).
        else if (!temp->left)
        {
            *treeptr = temp->right;
            free(temp);
        }
        else if (!temp->right)
        {
            *treeptr = temp->left;
            free(temp);
        }
        // Case 3: Node has two children.
        else
        {
            // Find the in-order successor (minimum in the right subtree).
            node *successor = temp->right;
            while (successor->left)
                successor = successor->left;

            // Replace the current node's data with the successor's data.
            temp->data = successor->data;

            // Recursively delete the successor node.
            delete_element(&temp->right, successor->data);
        }
    }
}

int main()
{
    BT *tree = create_BT();
    for (int i = 0; i < 7; i++)
        insert_element(&tree->root, i);
    printf("Pre-order\n");
    pre_order(tree->root);
    printf("In-order\n");
    in_order(tree->root);
    printf("Post-order\n");
    post_order(tree->root);
    search_element(tree->root, 0, 0, 0);
    delete_element(&tree->root, 2);
    printf("Pre-order\n");
    pre_order(tree->root);
    return 0;
}