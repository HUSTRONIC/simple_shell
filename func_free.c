#include "shell.h"
#include <stdio.h>

/**
 * f_error - frees all the allocated pointers.
 * @argv: points to a pointer of an  array
 * @arg: pointer to a pointer of an array
 *
 * Return: void.
 */
void f_error(char **argv, char *arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * f_tok - frees the required memory allocated
 * @ptr: the pointer to the allocated memory required.
 *
 * Return: void.
 */
void f_tok(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}


/**
 * f_path - this frees the variable to the PATH
 *
 * Return: voidg
 */
void f_path(void)
{
	if (environ != NULL)
	{
		size_t i = 0;

		while (environ[i] != NULL)
		{
			if (f_strncmp(environ[i], "PATH=", 5) == 0)
			{
				free(environ[i]);
				environ[i] = NULL;
				break;
			}
			i++;
		}
	}
}
