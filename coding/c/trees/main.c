#include <stdio.h>
#include "bst.h"

/*  NOTE
    : please make new nodes using the functions below:
        in_node(&node tree, int value) or nw_node(&node tree, int value)
    : and free the nodes using
        free_t(&node tree)
    : This is to avoid memory leaks
*/

int main()
{
    node *mytree = nw_node(4);
    in_node(&mytree, 2), in_node(&mytree, 6), in_node(&mytree, 1), in_node(&mytree, 3);
    in_node(&mytree, 5), in_node(&mytree, 7), in_node(&mytree, 8);

    print_a(&mytree);
    printf("\n");

    rm_node(&mytree, 10);
    rm_node(&mytree, 8);
    print_a(&mytree);
    printf("\n");

    sc_node(&mytree, 23);
    sc_node(&mytree, 3);

    free_t(&mytree);
    return 0;
}