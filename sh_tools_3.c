#include "lib_shell.h"

/**
 * reverse_S - reverse String
 * @str: string
 * @len: int
 * Return: void
*/
void reverse_S(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

/**
 * is_cmd_exist - is command exist
 * @cmd: strin
 * Return: int
*/
int is_cmd_exist(char *cmd)
{
	char *command[] = {"exit", "env", NULL};
	int i;

	for (i = 0; command[i]; i++)
	{
		if (_strcmp(cmd, command[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_cmd - handle command
 * @cmd: string of string
 * @argv: argumant system
 * @status: string
 * @i: int
 * Return: void
*/
void handle_cmd(char **cmd, char **argv, int *status, int i)
{
	if (_strcmp(cmd[0], "exit") == 0)
		sh_exit(cmd, argv, status, i);
	else
	{
		if (_strcmp(cmd[0], "env") == 0)
			env_print(cmd, status);
	}
}

/**
 * sh_exit - exit function
 * @cmd: string of string
 * @argv: argumant system
 * @status: string
 * @i: int
 * Return: void
*/
void sh_exit(char **cmd, char **argv, int *status, int i)
{
	int exit_vla = (*status);
	char *index, msg_err[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_number_positive(cmd[1]))
		{
			exit_vla = _atoi(cmd[1]);
		}
		else
		{
			index = _itoa(i);
			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, index, _strlen(index));
			write(STDOUT_FILENO, msg_err, _strlen(msg_err));
			write(STDOUT_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDOUT_FILENO, "\n", 1);
			free(index);
			FreeArray2DOfString(cmd);
			(*status) = 2;
			return;
		}
	}
	FreeArray2DOfString(cmd);
	exit(exit_vla);
}

/**
 * env_print - afficher les environ
 * @cmd: string of string
 * @status: int
 * Return: void
*/
void env_print(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	FreeArray2DOfString(cmd);
	(*status) = 0;
}
