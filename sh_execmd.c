#include "lib_shell.h"

/**
* execmd - execut command
* @cmd: Count of arguments
* @argv: Arguments
* @i: incriment
* Return: (WEXITSTATUS(statu) Always (success)
*/
int execmd(char **cmd, char **argv, int i)
{
	char *r_command = NULL;
	pid_t p_id;
	int statu;

	r_command = _getpath(cmd[0]);
	if (!r_command)
	{
		printerror(argv[0], cmd[0], i);
		FreeArray2DOfString(cmd);
		return (127);
	}

	p_id = fork();

	if (p_id == 0) /* child exucut */
	{
		if (execve(r_command, cmd, environ) == -1)
		{
			/* perror(argv[0]); */
			free(r_command), r_command = NULL;
			FreeArray2DOfString(cmd);
			/* exit(0); */
		}
	}
	else
	{
		waitpid(p_id, &statu, 0);
		FreeArray2DOfString(cmd);
		free(r_command), r_command = NULL;
	}

	return (WEXITSTATUS(statu));
}
