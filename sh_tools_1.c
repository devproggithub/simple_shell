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

	for (i = 0; i <= le; i++)
		p[i] = str[i];

	return (p);
}

int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;

		s1++;
		s2++;
		cmp = (int) *s1 - (int)*s2;
	}
	return (cmp);
}

int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
