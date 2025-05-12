#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

struct tTree {
    int info;
    struct tTree *left;
    struct tTree *right;
};

typedef struct tTree Tree;

// Tree constructor
Tree* new_tree();

// Inserts new node according to value
Tree* insert_node(Tree*, int);

// Clears tree
Tree* clear(Tree*);

// Shows all elements in tree
void show_tree(Tree*, int);

// Counts total number of nodes in tree
int nodes_number(Tree*);

// Calculates maximum height of the tree
int height(Tree*);

// Balances tree (following rules from AVL Tree data structure)
Tree* balance(Tree*);

Tree* left_rotation(Tree*); // Rotation to the right

Tree* right_rotation(Tree*); // Rotation to the left

// Calculates tree's balance factor
int factor(Tree*);

#endif // BINARY_TREE_H_INCLUDED
