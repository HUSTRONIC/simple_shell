#include "shell.h"

/**
 * f_env - This will Print all the
 * environment variables.
 *
 * Return: void.
 */
int f_env(void)
{
	int k;

	for (k = 0; environ[k]; k++)
	{
		f_put(environ[k]);
		_putchar('\n');
	}

	return (0);
}
