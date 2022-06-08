#ifndef TREE
#define TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum file_type {D, F} file_type_t;

typedef struct node{
    file_type_t type;
    struct node *parent, *child, *sibling;
    char *name;
} node_t;

void init ();
void get_cwd_name (char *name);

node_t* create_node (char *name, file_type_t type);

#endif