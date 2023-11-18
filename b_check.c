 #include "shell.h"

/**
 * check__built -this finds out whether
 * the command is builtin
 * @args: required argumentsfor the array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int check_built(char **args)
{
	if (!args[0])
		return (0);
	if (!_strcmp(args[0], "exit"))
		func_exit(args);
	else if (!_strcmp(args[0], "env"))
		shell_env();
	else if (!_strcmp(args[0], "setenv"))
		shell_setenv(args);
	else if (!_strcmp(args[0], "unsetenv"))
		shell_unsetenv(args);
	else if (!_strcmp(args[0], "help"))
		shell_help();
	else if (!_strcmp(args[0], "cd"))
		shell_cd(args);
	else if (!_strcmp(args[0], "clear"))
		shell_clear(args);
	else
		return (0);
	return (1);
}
