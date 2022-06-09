#include "tree.h"

node_t *cwd, *root;

node_t* create_node (char *name, file_type_t type)
{
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->name = (char *) malloc(64 * sizeof(char));

    node->parent = node->child = node->sibling = NULL;
    
    strcpy(node->name, name);
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

node_t* search_siblings (node_t *node, char *name)
{
    node_t *sib_node = node;

    while (sib_node) {
        if (strcmp(name, sib_node->name) == 0) {
            sib_node = (sib_node->type == F) ? NULL : sib_node;
            break;
        }

        sib_node = sib_node->sibling;
    }

    return sib_node;
}

node_t* search_cwd (char *path)
{
    return search_siblings (cwd, path);
}

node_t* search_for_node (char *path)
{
    node_t *node = cwd;
    if (path[0] == '/')
        node = root;

    //strtok is used to tokenize the string with the occurrences of /
    char *name;
    name = strtok(path, "/");

    while (name && node) {
        if (strcmp(name, "..") == 0) {
            node = node->parent;
        } else {
            node = search_siblings(node->child, name);
        }

        name = strtok(NULL, "/");
    }

    return node;
}

int make_directory (node_t *node, char *dir_name)
{
    //Errors
    if (node == NULL) {
        printf ("Error: Invalid path\n");
        return -1;
    } else if (search_siblings(node->child, dir_name) != NULL) {
        printf ("Error: Already exists\n");
        return -1;
    }

    //Actual function
    node_t *new_dir = create_node(dir_name, D);
    new_dir->parent = node;

    if (!node->child) {
        node->child = new_dir;
    } else {
        node = node->child;

        while (node->sibling)
            node = node->sibling;

        node->sibling = new_dir;
    }

    return 0;
}

int make_directory_in_cwd (char *dir_name)
{
    return make_directory (cwd, dir_name);
}

int list_directory (char *path)
{
    node_t *node = cwd;

    if (path)
        node = search_for_node (path);

    if (node == NULL) {
        printf("Error: Invalid path\n");
        return -1;
    }

    node = node->child;

    while (node) {
        printf("%s: %c  ", node->name, (node->type == D) ? 'D' : 'F');

        node = node->sibling;
    }

    printf("\n");

    return 0;
}