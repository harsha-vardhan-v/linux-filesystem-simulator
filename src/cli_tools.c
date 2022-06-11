#include "cli_tools.h"

char line[LINE_LENGTH], command[COMMAND_LENGTH], pathname[PATH_LENGTH];

char *cmd[] = { "mkdir", "rmdir", "cd", "ls", "pwd", "touch", "rm", "menu"};
int (*fptr[]) (char *) = { (int (*) ()) mkdir, rmdir, cd, ls, pwd, touch, rm, menu };

void prompt (node_t *cwd)
{
    line[0] = command[0] = pathname[0] = '\0';
    printf(">> ");
    fgets(line, LINE_LENGTH, stdin);
    line[strlen(line) - 1] = '\0';

    sscanf(line, "%s %s", command, pathname);
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