#include "cli_tools.h"

#include <stdio.h>
#include <string.h>

char line[LINE_LENGTH], command[COMMAND_LENGTH], path[PATH_LENGTH];

void prompt () {
    printf("%s >> ", "/"); 
    fgets(line, COMMAND_LENGTH, stdin);
    line[strlen(line) - 1] = '\0';

    sscanf(line, "%s %s", command, path);
}