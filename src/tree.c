#include "tree.h"

node_t *cwd, *root;

node_t* create_node (char *name, file_type_t type)
{
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->name = (char *) malloc(64 * sizeof(char));

    node->parent = node->child = node->sibling = NULL;
    
    strcpy(node->name, "/");
    node->type = type;

    return node;
}

void init ()
{
    root = create_node("/", D);
    cwd = root;
}

void get_cwd_name (char *name)
{
    strcpy(name, cwd->name);
}