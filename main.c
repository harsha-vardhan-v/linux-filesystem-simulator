#include "src/tree.h"
#include "src/cli_tools.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main (int argc, char *argv[])
{
    init();
    while(true) {
        printf("\n");
        prompt();
        
        if (strcmp(line, "quit") == 0)
            break;

        int index = find_cmd(command);

        if (index == -1) {
            printf("Error: Unknown command. Use command \"menu\" to view availbable commands\n");
            continue;
        }

        fptr[find_cmd(command)] (path);
    }
    
    return EXIT_SUCCESS;
}