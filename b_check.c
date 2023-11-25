 #include "shell.h"

/**
 * check_built -this finds out whether
 * the command is builtin
 * @args: required argumentsfor the array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int check_built(char **args)
{
	if (!args[0])
		return (0);
	if (!f_strcmp(args[0], "exit"))
		func_exit(args);
	else if (!f_strcmp(args[0], "env"))
		f_env();
	else if (!f_strcmp(args[0], "setenv"))
		f_set_env(args);
	else if (!f_strcmp(args[0], "unsetenv"))
		f_unset_env(args);
	else if (!f_strcmp(args[0], "help"))
		f_help();
	else if (!f_strcmp(args[0], "cd"))
		_cd(args);
	else if (!f_strcmp(args[0], "clear"))
		f_clear(args);
	else
		return (0);
	return (1);
}
