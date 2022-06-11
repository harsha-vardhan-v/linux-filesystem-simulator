#ifndef CMD_FUNC
#define CMD_FUNC

#include "tree.h"

#include <stdio.h>
#include <libgen.h>

int mkdir (char *path);
int rmdir (char *path);
int cd (char *path);
int ls (char *path);
int pwd ();
int touch (char *path);
int rm (char *path);
int save (char *filename);
int reload (char *filename);
int menu (void);

#endif