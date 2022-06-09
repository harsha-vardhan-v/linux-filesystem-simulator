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
void get_cwd_path (char *path);

node_t* create_node (char *name, file_type_t type);
node_t* search_cwd (char *name);
node_t* search_for_node (char *path);
int make_directory (node_t *node, char *dir_name);
int make_directory_in_cwd (char *dir_name);
int list_directory (char *path);
int change_directory (char *path);

#endif