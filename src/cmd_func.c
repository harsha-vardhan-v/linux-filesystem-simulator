#include "cmd_func.h"

int create_file (char *path, file_type_t type)
{
    if (strlen(path) == 0) {
        printf ("Error: Invalid path\n");
        return -1;
    }

    // Returns pointer of the last occurence of /
    char *basename = strrchr(path, '/');

    if (!basename) {
        if (insert_node_in_cwd(path, type) == 0) {
            printf("Created %s %s\n", (type == D) ? "directory" : "file", path);
            return 0;
        }

        return -1;
    } else {
        //Currently basename points to the last / character
        //Make the / to '\0' and then increment basename pointer
        //This creates two strings path - with everything before the / and basename - with everything after the /
        *basename = '\0';
        basename++;

        // If path becomes '\0' then it means that first / is the last occurence that means path has to be /
        node_t *to_create = search_for_node((strlen(path) != 0) ? path : "/");

        if (!to_create) {
            printf ("Error: Invalid path\n");
            return -1;
        }

        // //Insert node
        if (insert_node(to_create, basename, type) == 0) {
            printf("Created %s %s\n", (type == D) ? "directory" : "file", basename);
            return 0;
        }
    }

    return -1;
}

int delete_file (char *path, file_type_t type)
{
    if (strlen(path) == 0) {
        printf ("Error: Invalid path\n");
        return -1;
    }

    // Returns pointer of the last occurence of /
    char *pathcpy = (char *) malloc(64 * sizeof(char));
    strcpy(pathcpy, path);
    node_t *to_delete = search_for_node(path);

    if (!to_delete) {
        printf ("Error: Invalid path\n");
        free(pathcpy);
        return -1;
    } else if (to_delete->type != type) {
        printf ("Error: Not a %s\n", (type == D) ? "directory" : "file");
        free(pathcpy);
        return -1;
    }

    if (remove_node(to_delete) == 0) {
        printf ("Deleted %s %s\n", (type == D) ? "directory" : "file", basename(pathcpy));
        free(pathcpy);
        return 0;
    }

    free(pathcpy);
    return -1;
}

int mkdir (char *path)
{
    return create_file(path, D);
}

int rmdir (char *path)
{
    return delete_file(path, D);
}

int cd (char *path)
{
    return change_directory(path);
}

int ls (char *path)
{
    return list_directory(path);
}

int pwd ()
{
    char *name = (char *) malloc(64 * sizeof(char));
    name[0] = '\0';

    get_cwd_path(name);

    if (name[0] == '\0') {
        printf("Error: Unable to get the current working directory\n");
    }

    printf("Present working directory: %s\n", name);
    free(name);

    return 0;
}

int touch (char *path)
{
    // Need to change search specifications accordingly
    return create_file(path, F);
}

int rm (char *path)
{
    return delete_file(path, F);
}

int menu (void)
{
    printf("\n\tCommands available\n");
    printf("1) mkdir\n");
    printf("2) rmdir\n");
    printf("3) cd\n");
    printf("4) ls\n");
    printf("5) pwd\n");
    printf("6) touch\n");
    printf("7) rm\n");
    printf("8) menu\n");
    printf("9) quit\n");

    return 0;
}