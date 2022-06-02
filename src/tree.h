#ifndef TREE
#define TREE

typedef struct node{
    char *name;
    struct node *parent, *child, *sibling;
} node_t;

#endif