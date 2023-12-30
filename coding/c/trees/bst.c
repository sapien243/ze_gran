#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/// @brief TO ONLY BE USED IN rm_node();
/// @param &node root->right
/// @return node *  |>  ptr to a node with the min value in the right of the root:
node *mini(node **root);

node *nw_node(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    if (!temp)
    {
        printf("Err: Memory not allocated. Returned NULL\n");
        return NULL;
    }
    temp->value = data;
    temp->left = NULL, temp->right = NULL;
    return temp;
}

int in_node(node **root, int fruit)
{
    if (!*root)
    {
        *root = nw_node(fruit);
        if (*root)
            return 0;
    }
    else if ((*root)->value >= fruit)
        return in_node(&(*root)->left, fruit);

    else if ((*root)->value < fruit)
        return in_node(&(*root)->right, fruit);

    printf("Err: Failed to insert %i\n", fruit);
    return 1;
}

int rm_node(node **root, int fruit)
{
    if (!*root)
        printf("%i not found in this tree\n", fruit);

    else if ((*root)->value > fruit)
        return rm_node(&(*root)->left, fruit);

    else if ((*root)->value < fruit)
        return rm_node(&(*root)->right, fruit);

    else if ((*root)->value == fruit)
    {
        node *temp = *root;
        if (!temp->right && !temp->left)
            *root = NULL;

        else if (!temp->right)
            *root = temp->left;

        else if (!temp->left)
            *root = temp->right;

        else
        {
            *root = mini(&temp->right);
            (*root)->right = temp->right, (*root)->left = temp->left;
        }
        free(temp);
        return 0;
    }
    return 1;
}
node *mini(node **root)
{
    node *temp = *root;
    if (!temp->left)
    {
        *root = (!temp->right) ? NULL : temp->right;
        return temp;
    }
    return mini(&temp->left);
}

int sc_node(node **root, int fruit)
{
    if (!*root)
        printf("%i not found in this tree\n", fruit);

    else if ((*root)->value == fruit)
    {
        printf("%i found in this tree\n", fruit);
        return 0;
    }
    else if ((*root)->value > fruit)
        return sc_node(&(*root)->left, fruit);

    else if ((*root)->value < fruit)
        return sc_node(&(*root)->right, fruit);

    return 1;
}

void print_a(node **root)
{
    if (!*root)
    {
        printf("node is empty\n");
        return;
    }
    if ((*root)->left)
        print_a(&(*root)->left);

    printf("%i ", (*root)->value);
    if ((*root)->right)
        print_a(&(*root)->right);
}

void free_t(node **root)
{
    if (!*root)
    {
        printf("node is empty\n");
        return;
    }
    if ((*root)->left)
        free_t(&(*root)->left);

    if ((*root)->right)
        free_t(&(*root)->right);

    free(*root);
}
