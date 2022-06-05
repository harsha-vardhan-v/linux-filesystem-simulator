#include "cmd_func.h"

int mkdir (char *path)
{
    printf("mkdir\n");

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

int pwd (void)
{
    printf("pwd\n");

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
    printf("mkdir\n");
    printf("rmdir\n");
    printf("cd\n");
    printf("ls\n");
    printf("pwd\n");
    printf("touch\n");
    printf("rm\n");
    printf("save\n");
    printf("reload\n");

    return 0;
}