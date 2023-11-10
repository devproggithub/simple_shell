#include "lib_shell.h"

/* sh_split_line */
char **sh_split_line(char *l)
{
	char *t = NULL, *copyline = NULL;
	char **cmd = NULL;
	int c = 0, i = 0;

	if (!l)
		return (NULL);

	copyline = _strdup(l);

	t = strtok(copyline, DIAM);

	if (t == NULL)
	{
		free(l), l = NULL;
		free(copyline), copyline = NULL;
		return (NULL);
	}

	while (t)
	{
		c++;
		t = strtok(NULL, DIAM);
	}
	free(copyline), copyline = NULL;

	cmd = malloc(sizeof(char *) * (c + 1));
	if (!cmd)
	{
		free(l), l = NULL;
		return (NULL);
	}

	t = strtok(l, DIAM);
	while (t)
	{
		cmd[i] = _strdup(t);
		t = strtok(NULL, DIAM);
		i++;
	}

	free(l), l = NULL;
	cmd[i] = NULL;
	return (cmd);
}
