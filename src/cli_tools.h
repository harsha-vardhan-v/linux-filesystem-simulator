#ifndef CLI_TOOLS
#define CLI_TOOLS

#define LINE_LENGTH 128
#define COMMAND_LENGTH 16
#define PATH_LENGTH 64

extern char line[LINE_LENGTH], command[COMMAND_LENGTH], path[PATH_LENGTH];

void prompt (void);


#endif