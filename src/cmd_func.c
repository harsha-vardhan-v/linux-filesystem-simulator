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

    return 0;
}

int mkdir (char *path)
{
    return create_file(path, D);
}

int rmdir (char *path)
{
    printf("rmdir\n");

    return 0;
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
    return create_file(path, F);
}

int rm (char *path)
{
    printf("rm\n");

    return 0;
}

int save (char *filename)
{
    printf("save\n");

    return 0;
}

int reload (char *filename)
{
    printf("reload\n");

    return 0;
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
    printf("8) save\n");
    printf("9) reload\n");
    printf("10) menu\n");
    printf("11) quit\n");

    return 0;
}