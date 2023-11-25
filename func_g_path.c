#include "shell.h"

/**
 * func_g_path - This returns the required
 *  value of the PATH to the variable.
 *
 * Return: value of PATH to the pointer.
 */
char *func_g_path(void)
{
	return (f_g_env("PATH"));
}
