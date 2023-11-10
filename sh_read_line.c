#include "lib_shell.h"

/* read line */
char *sh_read_line(void)
{
	char *L = NULL;
	size_t s = 0;
	ssize_t n;

	if(isatty(STDIN_FILENO) == 1)
	    write(STDOUT_FILENO, "$ ", 2);

	n = getline(&L, &s, stdin);

	if (n == -1)
	{
		free(L);
		return (NULL);
	}

	return (L);
}
