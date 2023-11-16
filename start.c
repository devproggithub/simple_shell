#include "lib_shell.h"

/**
* main -simple Shell main function
* @ac: Count of arguments
* @argv: Arguments
* Return: 0 Always (success)
*/
int main(int ac, char **argv)
{
	char *line = NULL, **com = NULL;
	int Status = 0, i = 0;
	(void) ac;

	while (1)
	{

		line = sh_read_line();
		if (line == NULL) /* EOF Ctrl+D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (Status);
		}
		i++;
		/* free(line); */
		com = sh_split_line(line);
		if (!com)
			continue;

		if (is_cmd_exist(com[0]))
			handle_cmd(com, argv, &Status, i);
		else
			Status = execmd(com, argv, i);

	}

return (0);
}
