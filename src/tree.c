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

void get_cwd_path (char *path)
{
    node_t *node = cwd;

    char *buffer = (char *) malloc(64 * sizeof(char));
    buffer[0] = '\0';

    while (node) {
        if (strcmp(node->name, "/") == 0) {
            sprintf(buffer, "/%s", path);
            strcpy(path, buffer);
        } else {
            sprintf(buffer, "%s/%s", node->name, path);
            strcpy(path, buffer);
        }

        node = node->parent;
    }

    free(buffer);
}

node_t* search_siblings (node_t *node, char *name, file_type_t type)
{
    node_t *sib_node = node;

    while (sib_node) {
        if (strcmp(name, sib_node->name) == 0) {
            sib_node = (sib_node->type == type) ? sib_node : NULL;
            break;
        }

        sib_node = sib_node->sibling;
    }

    return sib_node;
}

node_t* search_cwd (char *path, file_type_t type)
{
    return search_siblings (cwd->child, path, type);
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
        if (strcmp(name, ".") == 0)
            node = cwd;
        else if (strcmp(name, "..") == 0) {
            node = node->parent;
        } else {
            node = search_siblings(node->child, name, D);
        }

        name = strtok(NULL, "/");
    }

    return node;
}

int insert_node (node_t *node, char *node_name, file_type_t node_type)
{
    //Checking for Errors
    if (node == NULL) {
        printf ("Error: Invalid path\n");
        return -1;
    } else if (search_siblings(node->child, node_name, node_type) != NULL) {
        printf ("Error: Already exists\n");
        return -1;
    }

    //Actual function
    node_t *new_node = create_node(node_name, node_type);
    new_node->parent = node;

    if (!node->child) {
        node->child = new_node;
    } else {
        node = node->child;

        while (node->sibling)
            node = node->sibling;

        node->sibling = new_node;
    }

    return 0;
}

int insert_node_in_cwd (char *node_name, file_type_t node_type)
{
    return insert_node(cwd, node_name, node_type);
}

int remove_node (node_t *node)
{
    //Checking for Errors
    if (node == NULL) {
        printf("Error: Invalid path\n");
        return -1;
    } else if (node == root) {
        printf("Error: Cannot delete root node\n");
        return -1; 
    } else if (node->type == D && node->child) {
        printf("Error: Directory not empty\n");
        return -1;
    }

    node_t *prev = node->parent, *to_delete;
    if (prev->child == node) {
        to_delete = node;
        prev->child = node->sibling;
    } else {
        prev = prev->child;

        while (prev->sibling != node)
            prev = prev->sibling;

        if (!prev)
            return -1;

        to_delete = node;
        prev->sibling = node->sibling;
    }

    free(to_delete);
    return 0;
}

int list_directory (char *path)
{
    node_t *node = cwd;

    if (strlen(path) != 0)
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

int change_directory (char *path)
{
    node_t *node;

    if (strlen(path) != 0) {
        node = search_for_node (path);
    }
    else
        node = root;

    if (node == NULL) {
        printf("Error: Invalid path\n");
        return -1;
    }

    cwd = node;
    printf("Changed to %s\n", cwd->name);

    return 0;
}