// ====== Declares bst functionality ======

#ifndef BST_H_
#define BST_H_
//

// ====== Structs in use ======

/// @brief acts as a node template of the b.s.t
typedef struct node
{
    int value;
    struct node *right, *left;
} node;

// ====== Prototypes ======

/// @brief create a new node & returns a ptr to it
/// @param int newValue
/// @return node *  ||  NULL if malloc() fails
node *nw_node(int data);

/// @brief creates a node with the newValue & insert it in the tree
/// @param &node root
/// @param int newValue
/// @return 0  ||  1 if insertion fails
int in_node(node **root, int fruit);

/// @brief removes a node with {value == fruit} from the tree
/// @param &node root
/// @param int fruit
/// @return 0  ||  1 if fruit is not in the tree or removal fails
int rm_node(node **root, int fruit);

/// @brief searches for a node with {value == fruit} in the tree
/// @param &node root
/// @param int fruit
/// @return 0  ||  1 if fruit is not in the tree or search fails
int sc_node(node **root, int fruit);

/// @brief prints the values in the tree in ascending order
/// @param &node root
/// @return void
void print_a(node **root);

/// @brief frees all the nodes in the tree
/// @param &node root
/// @return void
void free_t(node **root);
//

//
#endif // BST_H
