#include "src/tree.h"
#include "src/cli_tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


node_t *root, *cwd;

int main (int argc, char *argv[])
{
    while(true) {
        prompt();
        
        if (strcmp(line, "quit") == 0)
            break;

        printf("command: %s, command index: %d, pathname: %s\n", command, find_cmd(command), path);
    }
    
    return EXIT_SUCCESS;
}