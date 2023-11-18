#include "shell.h"

/**
 * func_exit - this will Exit the shell.
 * @args: the required arguments.
 *
 * Return: Nothing.
 */
void func_exit(char **args)
{
	int _stat = 0;

	if (args[1] != NULL)
	{
		_stat = _atoi(args[1]);
	}
	free_tokens(args);
	f_l_put();
	exit(_stat);
}
