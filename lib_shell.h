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

/* sh_tools_1.c */
char *_strdup(const char *str);
int _strcmp(char *s, char *c);
int _strlen(char *s);
char *_strcat(char *d, char *s);
char *_strcpy(char *d, char *s);

/* sh_tools_2.c */
void FreeArray2DOfString(char **ar);
char *_getenv(char *name);
char *_getpath(char *cmd);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int n);

/* sh_tools_3.c */
void reverse_S(char *str, int len);
int is_cmd_exist(char *cmd);
void handle_cmd(char **cmd, char **argv, int *Status, int i);
void sh_exit(char **cmd, char **argv, int *Status, int i);
void env_print(char **cmd, int *Status);

/* sh_tools_4.c */
int is_number_positive(char *str);
int _atoi(char *str);

/* sh_split_line.c */
char **sh_split_line(char *line);

/* sh_execmd.c */
int execmd(char **cmd, char **argv, int i);

#endif
