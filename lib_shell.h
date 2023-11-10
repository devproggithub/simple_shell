#ifndef LIB_SHELL_H
#define LIB_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DIAM " \t\n"
extern char **environ;

/* sh_read_line.c */
char *sh_read_line(void);

/* sh_tools.c */
char *_strdup(const char *str);
void FreeArray2DOfString(char **ar);

/*
* int _strcmp(char *s, char *c);
* int _strlen(char *s);
* char *_strcat(char *d, char *s);
* char *_strcpy(char *d, char *s);
*/

/* sh_split_line.c */
char **sh_split_line(char *line);

/* sh_execmd.c */
int execmd(char **cmd, char **argv);


#endif
