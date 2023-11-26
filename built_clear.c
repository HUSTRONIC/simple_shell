#include "shell.h"

/**
 * f_clear - This will clear the screen.
 * @args:  arguments
 *
 * Return: 1, else 0 to exit.
*/
int f_clear(char **args)
{
	(void)args;

	f_put("\033[2J\033[H");
	return (1);
}
