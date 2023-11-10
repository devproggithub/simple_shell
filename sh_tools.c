#include "lib_shell.h"

/* _strdup */
char *_strdup(const char *str)
{
    char *p;
    int i, le = 0;

	if (str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		le++;
		str++;
	}
	str = str - le;
	p = malloc(sizeof(char) * (le + 1));

	if (p == NULL)
		return (NULL);

	for (i=0; i<=le; i++)
		p[i] = str[i];

    return (p);
}

void FreeArray2DOfString(char **ar)
{
	int i;
	if (!ar)
		return;

	for (i = 0; ar[i]; i++)
	{
		free(ar[i]);
		ar[i] = NULL;
	}
	free(ar), ar = NULL;
}
