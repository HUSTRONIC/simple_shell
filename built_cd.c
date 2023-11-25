#include "shell.h"

/**
 * _cd - This changes the current directory
 * @args: the required array of arguments
 */
void _cd(char **args)
{
	char *dir = args[1];
	int r;

	/* If no argument is provided, change to HOME directory */
	if (dir == NULL)
	{
		dir = f_g_env("HOME");
		if (dir == NULL)
		{
			f_put("cd: No HOME directory found\n");
			return;
		}
	}

	r = chdir(dir);
	if (r == -1)
	{
		perror("cd");
	}
}
