#ifndef CLI_TOOLS
#define CLI_TOOLS

#include "cmd_func.h"

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 128
#define COMMAND_LENGTH 16
#define PATH_LENGTH 64

extern char line[LINE_LENGTH], command[COMMAND_LENGTH], path[PATH_LENGTH];
extern int (*fptr[]) (char *);

void prompt (void);
int find_cmd (char *command);


#endif