#include "lib_shell.h"

/**
* _strdup -copier la chaîne de caractères initiale.
* @str: String
* Return: copier
*/
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

/**
* _strcmp - comparer deux chaînes
* @m: String 1
* @t: String 2
* Return: int
*/
int _strcmp(char *m, char *t)
{
	int cmp;

	cmp = (int)*m - (int)*t;
	while (*m)
	{
		if (*m != *t)
			break;

		m++;
		t++;
		cmp = (int) *m - (int)*t;
	}
	return (cmp);
}

/**
* _strlen - calculer la longueur
* @s: String
* Return: int
*/
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcat - rajouter à une chaîne
 * @dest: string 1
 * @src: string 2
 * Return: String
*/
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

/**
 * _strcpy - copier le contenu d'une chaîne
 * @dest: string 1
 * @src: string 2
 * Return: String
*/
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
