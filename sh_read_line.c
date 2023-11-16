#include "lib_shell.h"

/**
* sh_read_line - read line
* Return: line
*/
char *sh_read_line(void)
{
	char *L = NULL;
	int k;
	size_t s = 0;
	ssize_t n;

	k = isatty(STDIN_FILENO);

	if (k == 1)
		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&L, &s, stdin);

	if (n == -1)
	{
		free(L);
		return (NULL);
	}

	return (L);
}
