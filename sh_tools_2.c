#include "lib_shell.h"

/**
 * FreeArray2DOfString - Free Array 2D Of String
 * @ar: String
 * Return: void
*/
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

/**
 * _getenv - get environ récupérer le contenu d'une variable d'environnement
 * @name: name
 * Return: string
 */
char *_getenv(char *name)
{
	unsigned int i;
	char *t, *k, *val, *e;

	i = 0;
	while (environ[i] != NULL)
	{
		/* printf("%s\n", environ[i]); */
		t = _strdup(environ[i]);
		k = strtok(t, "=");
		if (_strcmp(k, name) == 0)
		{
			val = strtok(NULL, "\n");
			e = _strdup(val);
			free(t);
			return (e);
		}
		free(t), t = NULL;
		i++;
	}
	return (NULL);
}

/**
 * _getpath - get path
 * @cmd: String
 * Return: String
*/
char *_getpath(char *cmd)
{
	char *p_env, *f_cmd, *dir;
	int i;
	struct stat s;
	/* if the cmd is already path */
	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			/* if path exist */
			if (stat(cmd, &s) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	/* if the user unset path (can't get directories)*/
	p_env = _getenv("PATH");
	if (!p_env)
		return (NULL);
	/* try handle the path */
	dir = strtok(p_env, ":");
	while (dir)
	{
		/* size = len(directory) + len(cmd) + 2('/' and '\0') */
		f_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (f_cmd)
		{
			_strcpy(f_cmd, dir);
			_strcat(f_cmd, "/");
			_strcat(f_cmd, cmd);
			if (stat(f_cmd, &s) == 0)
			{
				free(p_env);
				return (f_cmd);
			}
			free(f_cmd), f_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(p_env);
	return (NULL);
}

/**
 * printerror - print error
 * @name: String
 * @cmd: String
 * @idx: int
 * Return: void
*/
void printerror(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));

	free(index);
}

/**
 * _itoa - Converts an integer to string
 * @n: int
 * Return: String
*/
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_S(buffer, i);
	return (_strdup(buffer));
}
