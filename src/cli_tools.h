#ifndef CLI_TOOLS
#define CLI_TOOLS

#include "cmd_func.h"

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 128
#define COMMAND_LENGTH 16
#define PATH_LENGTH 64
#define FPTR_LENGTH 10

extern char line[LINE_LENGTH], command[COMMAND_LENGTH], pathname[PATH_LENGTH];
extern int (*fptr[]) (char *);

void prompt ();
int find_cmd (char *command);


#endif