#include "shell.h"

/**
 * f_set_env - Set environment varriable value.
 * @args: Arguments
 *
 * Return: null
 */
int f_set_env(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		f_puterror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		f_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * f_unset_env - Unset an environment variable
 * @args: Arguments
 *
 * Return: null
 */
int f_unset_env(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		f_puterror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		f_puterror("unsetenv");
	}
	return (0);
}
