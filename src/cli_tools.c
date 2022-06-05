#include "cli_tools.h"

char line[LINE_LENGTH], command[COMMAND_LENGTH], path[PATH_LENGTH];

char *cmd[] = { "mkdir", "rmdir", "cd", "ls", "pwd", "touch", "rm", "save", "reload", "menu", "quit" };
int (*fptr[]) (char *) = { (int (*) ()) mkdir, rmdir, cd, ls, pwd, touch, rm, save, reload, menu };

void prompt (void)
{
    printf("%s >> ", "/"); 
    fgets(line, COMMAND_LENGTH, stdin);
    line[strlen(line) - 1] = '\0';

    sscanf(line, "%s %s", command, path);
}

int find_cmd (char *command)
{
    int i=0;

    while (cmd[i]) {
        if (strcmp(cmd[i], command) == 0)
            return i;

        i++;
    }

    return -1;
}