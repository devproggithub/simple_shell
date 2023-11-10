#include "lib_shell.h"

/* execmd */
int execmd(char **cmd, char **argv)
{
	/* char *command = NULL; */
	pid_t p_id;
	int statu;

	p_id = fork();

	if (p_id == 0) /* child exucut */
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			FreeArray2DOfString(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(p_id, &statu, 0);
		FreeArray2DOfString(cmd);
	}

	return (WEXITSTATUS(statu));
}
