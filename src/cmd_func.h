#ifndef CMD_FUNC
#define CMD_FUNC

#include <stdio.h>

int mkdir (char *path);
int rmdir (char *path);
int cd (char *path);
int ls (void);
int pwd (void);
int touch (char *path);
int rm (char *path);
int save (char *filename);
int reload (char *filename);
int menu (void);

#endif