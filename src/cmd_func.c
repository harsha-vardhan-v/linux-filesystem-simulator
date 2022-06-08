#include "cmd_func.h"

int mkdir (char *path)
{
    if (strlen(path) == 0) {
        printf ("Error: Invalid path\n");
        return -1;
    }

    // Returns pointer of the last occurence of /
    char *basename = strrchr(path, '/');

    if (!basename) {
        printf("path: \n");
        printf("basename: %s\n", path);
        make_directory_in_cwd(path);
        printf("Created directory\n");
    } else {
        //Currently basename points to the last / character
        //Make the / to '\0' and then increment basename pointer
        //This creates two strings path - with everything before the / and basename - with everything after the /
        *basename = '\0';
        basename++;

        printf("path: %s\n", path ? path : "/");
        printf("basename: %s\n", basename);

        // If path becomes '\0' then it means that first / is the last occurence that means path has to be /
        node_t *to_create = search_for_node(path ? path : "/");

        printf("Got node with name: %s\n", to_create->name);

        if (to_create == NULL) {
            printf ("Error: Invalid path\n");
            return -1;
        }

        //Insert node
        make_directory(to_create, basename);
        printf("Created directory\n");
    }

    return 0;
}

int rmdir (char *path)
{
    printf("rmdir\n");

    return 0;
}

int cd (char *path)
{
    printf("cd\n");

    return 0;
}

int ls (void)
{
    printf("ls\n");

    return 0;
}

int pwd ()
{
    char *name = (char *) malloc(64 * sizeof(char));
    name[0] = '\0';

    get_cwd_name(name);

    if (name[0] == '\0') {
        printf("Error: Unable to get the current working directory\n");
    }

    printf("Present working directory: %s\n", name);
    free(name);

    return 0;
}

int touch (char *path)
{
    printf("touch\n");

    return 0;
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