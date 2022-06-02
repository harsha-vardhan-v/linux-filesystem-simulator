#ifndef TREE
#define TREE

typedef struct node{
    char *name;
    node *parent, *child, *sibling;
} node_t;

#endif